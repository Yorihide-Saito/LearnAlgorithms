#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
    }

    int best = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cross = 0;
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].first;
            int v = edges[j].second;
            if ((mask >> u) & 1 ^ ((mask >> v) & 1)) cross++;
            best = max(best, cross);
        }
    }

    cout << (m - best) << endl;
    return 0;
}