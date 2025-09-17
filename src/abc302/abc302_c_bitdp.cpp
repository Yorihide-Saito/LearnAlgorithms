#include<iostream>
#include<vector>
using namespace std;

bool isDist1(const string& a, const string& b, int M) {
    int d = 0;
    for (int i = 0; i < M; i++) if (a[i] != b[i]) d++;
    return d == 1;
}

vector<vector<int>> buildGraph(const vector<string>& S, int N, int M) {
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            if (i != j) {
                if (isDist1(S[i], S[j], M)) graph[i][j] = 1;
            }
        }
    }
    return graph;
}

bool hasHamiltonianPathBitDP(const vector<vector<int>>& graph, int N) {
    int FULL = (1 << N);
    vector<vector<char>> dp(FULL, vector<char>(N, 0));
    for (int v = 0; v < N; v++) dp[1<<v][v] = 1;

    for (int mask = 0; mask < FULL; mask++) {
        for (int v = 0; v < N; v++) if (dp[mask][v]) {
            for (int u = 0; u < N; u++) {
                if (!(mask & (1 << u)) && graph[v][u]) {
                    dp[mask | (1 << u)][u] = 1;
                }
            }
        }
    }
    for (int v = 0; v < N; v++) if (dp[FULL - 1][v]) return true;
    return false;
}

int main() {
    int N, M; cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<int>> graph = buildGraph(S, N, M);
    cout << (hasHamiltonianPathBitDP(graph, N) ? "Yes" : "No") << endl;
    return 0;
}