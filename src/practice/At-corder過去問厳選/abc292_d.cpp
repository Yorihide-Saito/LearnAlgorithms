#include<iostream>
#include<vector>
#include<numeric>
#include<utility>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int main() {
    int N, M; cin >> N >> M;

    vector<pair<int, int>> edges;
    DSU dsu(N);
    for (int i = 0; i < M; i++) {
        int U, V; cin >> U >> V;
        dsu.merge(U, V);
        edges.emplace_back(U, V);
    }

    vector<int> edge_group(N + 1, 0), node_group(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        node_group[dsu.find(i)]++;
    }

    for (int i = 0; i < M; i++) {
        edge_group[dsu.find(edges[i].first)]++;
    }

    for (int i = 1; i <= N; i++) {
        if (node_group[i] == edge_group[i]) continue;
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}