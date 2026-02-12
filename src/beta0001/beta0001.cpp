#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

const ll INF = (1LL<<60);

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N + 1);
    vector<int> B(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, -INF));
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = B[i]; j <= M; j++) {
            if (j == B[i]) dp[i][j] = max(dp[i][j], A[i]);

            for (int k = max(1, i-K); k <= i-1; k++) {
                if (dp[k][j - B[i]] == -INF) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - B[i]] + A[i]);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}