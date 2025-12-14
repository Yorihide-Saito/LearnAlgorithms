#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

static const int LIMIT = 1000000;

// abc284_e
// https://atcoder.jp/contests/abc284/tasks/abc284_e

int main() {
    ll N, M; cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<char> used(N, 0);
    int ans = 0;

    auto dfs = [&](auto&& self, int v) -> void {
        if (ans >= LIMIT) return;

        ans++;
        if (ans >= LIMIT) return;

        used[v] = 1;
        for (int to : graph[v]) {
            if (used[to]) continue;
            self(self, to);
            if (ans >= LIMIT) break;
        }
        used[v] = 0;
    }

    dfs(dfs, 0);

    cout << min(ans, LIMIT) << endl;
    return 0;
}