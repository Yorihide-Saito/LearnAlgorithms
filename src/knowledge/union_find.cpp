// ============================================================
// UnionFind (素集合データ構造)
// 使いどころ: グループ分け・連結判定・「辺を追加」クエリ
//   削除クエリは苦手 → クエリ逆順で追加に読み替える(ABC120D)
// 計算量: ほぼ O(α(N)) ≒ 定数
// 代表問題: ABC177D, ABC120D, 典型90-012
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) : par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }
    int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return sz[root(x)]; }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int main() {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);
    cout << boolalpha << uf.same(0, 2) << '\n'; // true
    cout << uf.size(0) << '\n';                 // 3
    return 0;
}
