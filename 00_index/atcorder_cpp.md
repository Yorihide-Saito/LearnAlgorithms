# C++ Competitive Programming Cheatsheet (AtCoder向け)

---

## 0. お約束（高速入出力・別名・定数）

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using PII = pair<int,int>;
using PLL = pair<long long,long long>;
template<class T> using V = vector<T>;

constexpr ll INF  = (1LL<<60);        // 十分大きい値
constexpr int IINF = (1<<30);
constexpr int MOD  = 1'000'000'007;   // 998244353もよく使う

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
```

---

## 1. 便利関数・イディオム

```cpp
template<class T> bool chmin(T& a, const T& b){ if(a>b){ a=b; return true; } return false; }
template<class T> bool chmax(T& a, const T& b){ if(a<b){ a=b; return true; } return false; }

#define ALL(x) begin(x), end(x)

const int dx4[4] = {1,0,-1,0};
const int dy4[4] = {0,1,0,-1};
const int dx8[8] = {1,1,0,-1,-1,-1,0,1};
const int dy8[8] = {0,1,1,1,0,-1,-1,-1};
```

---

## 2. よく使うコンテナ

```cpp
vector<int> a(n);
vector<vector<int>> g(n);
array<int,3> t = {x,y,z};

pair<int,int> p = {3,5};
map<int,int> mp;
unordered_map<int,int> ump;
set<int> st;
unordered_set<int> ust;

queue<int> q;
deque<int> dq;
stack<int> stc;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

bitset<200000> bs;
```

---

## 3. 典型テク

### 3.1 座標圧縮

```cpp
vector<int> xs = a;
sort(ALL(xs)); xs.erase(unique(ALL(xs)), xs.end());
a[i] = lower_bound(ALL(xs), a[i]) - xs.begin();
```

### 3.2 累積和（1D / 2D）

```cpp
// 1D
vector<ll> s(n+1,0);
for(int i=0;i<n;i++) s[i+1]=s[i]+a[i];
ll sum_lr = s[r]-s[l]; // [l,r)

// 2D
vector<vector<ll>> ps(h+1, vector<ll>(w+1));
for(int i=0;i<h;i++) for(int j=0;j<w;j++)
    ps[i+1][j+1]=ps[i+1][j]+ps[i][j+1]-ps[i][j]+grid[i][j];
```

### 3.3 いもす法

```cpp
vector<ll> diff(n+1,0);
diff[l]+=v; diff[r]-=v; // [l,r)
for(int i=1;i<n;i++) diff[i]+=diff[i-1];
```

### 3.4 BFS（グリッド）

```cpp
vector<vector<int>> dist(h, vector<int>(w, -1));
queue<pair<int,int>> q;
dist[sy][sx]=0; q.push({sy,sx});

while(!q.empty()){
    auto [y,x]=q.front(); q.pop();
    for(int k=0;k<4;k++){
        int ny=y+dy4[k], nx=x+dx4[k];
        if(ny<0||ny>=h||nx<0||nx>=w) continue;
        if(s[ny][nx]=='#' || dist[ny][nx]!=-1) continue;
        dist[ny][nx]=dist[y][x]+1;
        q.push({ny,nx});
    }
}
```

---

## 4. グラフの定番

### 4.1 Union-Find

```cpp
struct DSU{
    vector<int> p, sz;
    DSU(int n=0): p(n), sz(n,1){ iota(ALL(p),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b); if(a==b) return false;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; return true;
    }
    bool same(int a,int b){ return find(a)==find(b); }
};
```

### 4.2 ダイクストラ

```cpp
vector<ll> dist(n, INF);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
dist[0]=0; pq.push({0,0});

while(!pq.empty()){
    auto [d,v]=pq.top(); pq.pop();
    if(d>dist[v]) continue;
    for(auto [to,w]: g[v]){
        if(chmin(dist[to], d+w)) pq.push({dist[to], to});
    }
}
```

---

## 5. 数学まわり

### 5.1 べき乗（mod）

```cpp
ll modpow(ll a,ll e,ll mod){
    ll r=1%mod;
    while(e){
        if(e&1) r=(__int128)r*a%mod;
        a=(__int128)a*a%mod;
        e>>=1;
    }
    return r;
}
```

### 5.2 階乗・組合せ（mod）

```cpp
struct Comb {
    int n, mod; vector<ll> fact, ifact;
    Comb(int n,int mod): n(n), mod(mod), fact(n+1), ifact(n+1){
        fact[0]=1; for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
        ifact[n]=modpow(fact[n], mod-2, mod);
        for(int i=n;i>0;i--) ifact[i-1]=ifact[i]*i%mod;
    }
    ll C(int n,int k){ if(k<0||k>n) return 0; return fact[n]*ifact[k]%mod*ifact[n-k]%mod; }
};
```

---

## 6. 区間処理データ構造

### 6.1 Fenwick Tree（BIT）

```cpp
struct BIT{
    int n; vector<ll> bit;
    BIT(int n=0): n(n), bit(n+1,0){}
    void add(int i,ll v){ for(++i;i<=n;i+=i&-i) bit[i]+=v; }
    ll sum_prefix(int i){ ll r=0; for(++i;i>0;i-=i&-i) r+=bit[i]; return r; }
    ll sum(int l,int r){ return sum_prefix(r-1)-sum_prefix(l-1); } // [l,r)
};
```

### 6.2 Segment Tree

```cpp
struct SegTree{
    int n; ll ID=INF; vector<ll> seg;
    ll op(ll a,ll b){ return min(a,b); }
    SegTree(int n_=0){ init(n_); }
    void init(int n_){ n=1; while(n<n_) n<<=1; seg.assign(2*n, ID); }
    void update(int i,ll v){ i+=n; seg[i]=v; for(i>>=1;i;i>>=1) seg[i]=op(seg[i<<1],seg[i<<1|1]); }
    ll query(int l,int r){
        ll L=ID, R=ID;
        for(l+=n,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) L=op(L, seg[l++]);
            if(r&1) R=op(seg[--r], R);
        }
        return op(L,R);
    }
};
```

---

## 7. 比較関数・ハッシュ

```cpp
struct Node{ int v; ll d; };
struct Cmp{ bool operator()(const Node& a,const Node& b)const{ return a.d>b.d; } };
priority_queue<Node, vector<Node>, Cmp> pq;

struct PairHash{
    size_t operator()(const pair<int,int>& p) const {
        return (uint64_t)p.first<<32 ^ (uint64_t)p.second;
    }
};
unordered_map<pair<int,int>, int, PairHash> memo;
```

---

## 8. 文字列

```cpp
string s; cin>>s;
s.substr(l, len); // O(len)

// Z-alg, KMP など実装するときにvector<int>を使う
vector<int> z(s.size());
vector<int> pi(s.size());
```

---

## 9. 典型問題に対応するテンプレ

* **最短距離（重みなし）**：BFS
* **最短距離（非負重み）**：ダイクストラ
* **連結判定**：Union-Find
* **組合せmod**：Comb + modpow
* **反転数**：座標圧縮 + BIT
* **区間最小/最大/和**：SegTree
* **2D範囲和**：2D累積和

