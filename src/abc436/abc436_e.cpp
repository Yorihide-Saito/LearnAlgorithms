#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) cin >> P[i];

    // visited
    vector<char> vis(N + 1, 0);
    ll ans = 0;

    for (int start = 1; start <= N; start++) {
        if (vis[start]) continue;

        int cur = start;
        ll len = 0;
        while (!vis[cur]) {
            vis[cur] = 1;
            len++;
            cur = P[cur];
        }

        ans += len * (len - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}