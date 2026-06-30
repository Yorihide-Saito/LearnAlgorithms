#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<utility>
#include<queue>
using namespace std;

const long long INF = 4e18;

vector<long long> dijkstra(vector<vector<pair<int, long long>>> &graph, const int n, const int start) {
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while(!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d > dist[v]) continue;
        for (auto& [to, w] : graph[v]) {
            long long nd = d + w;
            if (nd < dist[to]) {
                dist[to] = nd;
                pq.emplace(nd, to);
            }
        }
    }
    return dist;
}

int main() {
    int N, M;
    long long Y;
    cin >> N >> M >> Y;
    vector<vector<pair<int, long long>>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int V, U;
        long long T;
        cin >> V >> U >> T;
        V--;
        U--;

        graph[V].push_back({U, T});
        graph[U].push_back({V, T});
    }

    for(int i = 0; i < N; i++) {
        long long X;
        cin >> X;

        graph[i].push_back({N, X});
        graph[N].push_back({i, X + Y});
    }

    vector<long long> dist = dijkstra(graph, N + 1, 0);
    for (int i = 1; i < N; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;

    return 0;
}