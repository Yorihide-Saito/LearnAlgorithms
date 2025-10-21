#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    DSU(int n): n(n), parent(n), sz(n,1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        // 経路圧縮
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    int h, w; cin >> h >> w;

    const long long n = 1LL * h * w;
    DSU dsu((int)n);
    vector<unsigned char> red(n, 0);

    auto id = [&](int r, int c) ->int {
        return (r-1) * w + (c-1);
    };

    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int q; cin >> q;

    while(q--) {
        int command;
        cin >> command;
        if (command == 1) {
            int r, c; cin >> r >> c;
            int v = id(r, c);
            if (!red[v]) {
                red[v] = 1;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 1 || nr > h || nc < 1|| nc > w) continue;
                    int u = id(nr, nc);
                    if (red[u]) dsu.unite(v, u);
                }
            }
        }
        else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            int a = id(ra, ca), b = id(rb, cb);
            if(red[a] && red[b] && dsu.same(a, b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}