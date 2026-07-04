// ============================================================
// ダイクストラ法 (正の重み付き最短路)
// 使いどころ: 重みが正の最短路。重みなしはBFS、0/1は01-BFSを使う
// 計算量: O((V+E) log V)
// 代表問題: ABC340D, 典型90-013(両側から2回)
// 罠: dist は ll / 訪問済みスキップ (d > dist[v]) を忘れない
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

vector<ll> dijkstra(int s, const vector<vector<pair<int, ll>>>& g) {
    int n = g.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d > dist[v]) continue;           // 古い情報はスキップ
        for (auto [to, w] : g[v]) {
            if (dist[v] + w < dist[to]) {
                dist[to] = dist[v] + w;
                pq.emplace(dist[to], to);
            }
        }
    }
    return dist;
}

int main() {
    // 0->1(5), 0->2(2), 2->1(1)
    vector<vector<pair<int, ll>>> g(3);
    g[0] = {{1, 5}, {2, 2}};
    g[2] = {{1, 1}};
    auto d = dijkstra(0, g);
    cout << d[1] << '\n'; // 3
    return 0;
}
