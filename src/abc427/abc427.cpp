#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define Graph vector<vector<int>>

int main() {
    int n, m; cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> color(n, -1);
    long long count = 0;

    for (int i = 0; i < n; i++){
        if (color[i] != -1) continue;
        // 0(1)から始める
        queue<int> q;
        color[i] = 0;
        q.push(i);

        while(!q.empty()) {
            int v = q.front(); q.pop();

            for (int i = 0; i < g[v].size(); i++) {
                int next = g[v][i];
                if (color[next] == -1) {
                    color[next] = color[v] ^ 1;
                    q.push(next);
                }
                else if (color[v] == color[next]) {
                    if (v < next) count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}