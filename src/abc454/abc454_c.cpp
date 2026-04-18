#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graf(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        graf[A].push_back(B);
    }

    vector<int> visited(N, 0);
    int ans = 0;
    auto dfs = [&](auto&& self, int v) -> void {
        if (visited[v]) return;
        visited[v] = 1;
        ans++;
        for (int to : graf[v]) {
            self(self, to);
        }
    };
    dfs(dfs, 0);
    cout << ans << endl;
    return 0;
}