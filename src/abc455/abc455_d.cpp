#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> C(Q, 0), P(Q, 0);
    for (int i = 0; i < Q; i++) {
        cin >> C[i] >> P[i];
        C[i]--;
        P[i]--;
    }

    UnionFind uf(N);

    vector<int> used(N, 0);

    for (int i = Q - 1; i >= 0; i--) {
        if (used[C[i]]) continue;
        uf.unite(P[i], C[i]);
        used[C[i]] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (used[i]) cout << "0 ";
        else cout << uf.size(i) << " ";
    }
    cout << endl;
    return 0;
}