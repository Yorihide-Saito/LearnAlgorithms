#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) {
        cin >> a;
        --a;
    }

    vector<int> indeg(N, 0);
    for (int i = 0; i < N; i++) {
        indeg[A[i]]++;
    }

    queue<int> q;
    vector<int> visited(N, 0);
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = 1;

        int to = A[v];
        indeg[to]--;
        if (indeg[to] == 0) {
            q.push(to);
        }
    }

    vector<int> seen(N, 0);
    for (int i = 0; i < N; i++) {
        if (!visited[i] && !seen[i]) {
            int cur = i;
            vector<int> cycle;

            while(!seen[cur]) {
                seen[cur] = 1;
                cycle.push_back(cur);
                cur = A[cur];
            }

            // これが1つのサイクル
            cout << "cycle length = " << cycle.size() << "\n";
            for (int v : cycle) cout << v + 1 << " ";
            cout << "\n";
        }
    }

    // vector<vector<int>> rev;
    // for (int i = 0; i < N; i++) {
    //     rev[A[i]].push_back(i);
    // }

    return 0;
}