#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    long long sum = 0;
    vector<long long> diff(N, 0);
    for (int i = 0; i < N; i++) {
        sum += A[i];
        diff[i] = B[i] - A[i];
    }

    const long long INF = 1LL << 60;

    vector<vector<long long>> dp(K + 1, vector<long long>(2, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        vector<vector<long long>> ndp(K + 1, vector<long long>(2, -INF));

        for (int j = 0; j <= K; j++) {
            ndp[j][0] = max(ndp[j][0], dp[j][0]);
            ndp[j][0] = max(ndp[j][0], dp[j][1]);

            if (dp[j][1] != -INF) {
                ndp[j][1] = max(ndp[j][1], dp[j][1] + diff[i]);
            }

            if (j < K && dp[j][0] != -INF) {
                ndp[j + 1][1] = max(ndp[j + 1][1], dp[j][0] + diff[i]);
            }
        }
        dp = move(ndp);
    }

    long long ans = 0;
    for (int i = 0; i <= K; i++) {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }

    cout << sum + ans << endl;
    return 0;
}
