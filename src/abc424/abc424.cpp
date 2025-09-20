#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> buildGraph(const vector<int> &a, const vector<int> &b, int N) {
    vector<vector<int>> graph(N+1);
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0 && b[i] == 0) {
            continue;
        }
        graph[a[i]].push_back(i);
        graph[b[i]].push_back(i);
    }
    return graph;
}

int main() {
    int N; cin >> N;
    vector<int> A(N+1, 0), B(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<int>> graph = buildGraph(A, B, N);
    // BFS
    vector<int> visited(N + 1, 0);
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (A[i] == 0 && B[i] == 0) {
            visited[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u = 0; u < graph[v].size(); u++) {
            if (!visited[graph[v][u]]) {
                visited[graph[v][u]] = 1;
                q.push(graph[v][u]);
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) if (visited[i]) count++;
    cout << count << endl;
    return 0;
}