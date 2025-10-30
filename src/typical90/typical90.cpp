#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

const int INF = (int) 1 << 30;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);

    while(!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto& [to, w] : graph[v]) {
            int nd = d + w;
            if (nd < dist[to]) {
                dist[to] = nd;
                pq.emplace(nd, to);
            }
        }
    }

    cout << dist[n - 1] << endl;
    return 0;
}