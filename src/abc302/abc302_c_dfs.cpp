#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isDist(const string& s1, const string& s2, int M) {
    int count = 0;
    for (int i = 0; i < M; i++) {
        if (s1[i] != s2[i]) count++;
    }
    if (count == 1) return true;
    else return false;
}

vector<vector<int>> buildGraph(const vector<string>&S, int N, int M) {
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isDist(S[i], S[j], M)) graph[i][j] = 1;
        }
    }
    return graph;
}

bool dfs(int v, int used_cnt, const vector<vector<int>>& graph, vector<int>& used, int N) {
    if (used_cnt == N) return true;
    for (int u = 0; u < N; u++) {
        if (!used[u] && graph[v][u]) {
            used[u] = 1;
            if (dfs(u, used_cnt + 1, graph, used, N)) return true;
            used[u] = 0;
        }
    }
    return false;
}

bool hasHamiltonianPathDFS(const vector<vector<int>>& graph, int N) {
    vector<int> used(N, 0);
    for (int s = 0; s < N; s++) {
        for (int i = 0; i < N; i++) used[i] = 0;
        used[s] = 1;
        if (dfs(s, 1 , graph, used, N)) return true;
    }
    return false;
}

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N, " ");

    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<int>> graph = buildGraph(S, N, M);
    cout << (hasHamiltonianPathDFS(graph, N) ? "Yes" : "No") << endl;
    return 0;
}