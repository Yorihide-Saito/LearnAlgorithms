#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// abc284_c
// https://atcoder.jp/contests/abc284/tasks/abc284_c

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int ans = 0;
    vector<int> visited(N, 0);
    // 各頂点に対して、dfs を行う。
    for (int i = 0; i < N; i++) {
        int start = i;
        if (visited[start]) continue;
        // dfs 開始
        stack<int> st;
        st.push(start);
        visited[c] = 1;
        while(!st.empty()) {
            int c = st.top(); st.pop();
            for (auto n : graph[c]) {
                if (visited[n]) continue;
                st.push(n);
                visited[c] = 1;
            }
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}