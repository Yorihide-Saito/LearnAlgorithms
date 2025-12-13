#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N, 0));
    int r, c, k;
    r = 0;
    c = (N - 1) / 2;
    k = 1;
    graph[r][c] = k;
    for (int i = 0; i < (N * N) - 1; i++) {
        k++;
        if (graph[((r + N) - 1) % N][((c + N) + 1) % N] == 0) {
            graph[((r + N) - 1) % N][((c + N) + 1) % N] = k;
            r = (r - 1) % N;
            c = (c + 1) % N;
        } else {
            graph[(r + N + 1) % N][c] = k;
            r = (r + 1) % N;
        }
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}