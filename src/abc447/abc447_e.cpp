#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1){
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);  // 経路圧縮
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        // union by size
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

const ll MOD = 998244353;

// 解法参考にした
// https://betrue12.hateblo.jp/entry/2019/03/03/224118

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) {
        cin >> U[i] >> V[i];
        U[i]--;
        V[i]--;
    }

    UnionFind uf(N);

    vector<ll> pw(M + 2);
    pw[0] = 1;
    for (int i = 1; i <= M + 1; i++) pw[i] = (pw[i - 1] * 2) % MOD;

    ll ans = 0;
    int cnt = N;
    for (int i = M-1; i >= 0; i--) {
        int c_u = U[i], c_v = V[i];
        if(!uf.same(c_u, c_v)) {
            if (cnt > 2) {
                uf.unite(c_u, c_v);
                cnt--;
            } else {
                ans = (ans + pw[i + 1]) % MOD;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}