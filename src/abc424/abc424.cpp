#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int>> buildGraph(const vector<pair<int, int>>& skill, int N) {
    vector<vector<int>> graph(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; i++) {
        int a = skill[i].first, b = skill[i].second;
        if (1 <= a) graph[a][i] = 1;
        if (1 <= b) graph[b][i] = 1;
    }
    return graph;
}

void bfs(vector<int>& start, const vector<vector<int>>& graph, vector<int>& haveSkill) {
    queue<int> q;
    for (int s : start) {
        if (!haveSkill[s]) { haveSkill[s] = 1; q.push(s); }
    }
    int N = (int)haveSkill.size() - 1;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u = 1; u <= N; ++u) {
            if (graph[v][u] && !haveSkill[u]) {
                haveSkill[u] = 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int N; cin >> N;
    vector<pair<int, int>> skill(N+1, { 0, 0 });
    for (int i = 0; i < N; i++) cin >> skill[i].first >> skill[i].second;

    vector<vector<int>> graph = buildGraph(skill, N);
    vector<int> haveSkill(N + 1, 0);

    vector<int> startPoint;
    for (int i = 1; i <= N; i++) {
        if (skill[i].first == 0 && skill[i].second == 0) {
            startPoint.push_back(i);
        }
    }

    bfs(startPoint, graph, haveSkill);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (haveSkill[i]) count += 1;
    }

    cout << count << endl;
}
