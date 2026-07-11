#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> R(M, 0), C(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i];
    }

    int ans = 0;
    vector<int> viR(N + 1, 0), viC(N + 1, 0);
    for (int i = M - 1; i >= 0; i--) {
        if ((viR[R[i]] == 0) && (viC[C[i]] == 0)) {
            ans++;
        }
        viR[R[i]]++;
        viC[C[i]]++;
    }

    cout << ans << endl;
    return 0;
}
