#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define Graph vector<vector<int>>

vector<int> dfs(const Graph &g, int s) {
    int n = g.size();
    vector<int> dist(n, -1);
    dist[s] = 0;

    stack<int> st({s});
    while(!st.empty()){
        int visit = st.top();
        st.pop();
        for (int i = 0; i < (int)g[visit].size(); i++) {
            int next = g[visit][i];
            if (dist[next] == -1) {
                st.push(next);
                dist[next] = dist[visit] + 1;
            }
        }
    }

    return dist;
}

int main() {
    int n; cin >> n;

    Graph g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist0 = dfs(g, 1);
    int mx = -1, mv = -1;
    for (int v = 1; v <= n; v++) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }

    vector<int> distmv = dfs(g, mv);
    mx = -1;
    for (int v = 1; v <= n; v++) {
        mx = max(mx, distmv[v]);
    }

    cout << mx + 1 << endl;

    return 0;
}