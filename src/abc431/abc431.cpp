#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

const long long NEG_INF = -(1LL << 60);

int main() {
    int N; cin >> N;
    vector<long long> W(N + 1, 0), H(N + 1, 0), B(N + 1, 0);
    long long sumW = 0;
    for (int i = 1; i <= N; i ++) {
        cin >> W[i] >> H[i] >> B[i];
        sumW += W[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(2 * sumW + 1, NEG_INF));
    dp[0][sumW] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2 * sumW + 1; j++) {
            if (dp[i - 1][j] == NEG_INF) continue;

            if (0 <= j + (W[i]) && j + (W[i]) <= 2 * sumW) {
                dp[i][j + W[i]] = max(dp[i][j + W[i]], dp[i-1][j] + H[i]);
            }
            if (0 <= j - (W[i]) && j - (W[i]) <= 2 * sumW) {
                dp[i][j - W[i]] = max(dp[i][j - W[i]], dp[i-1][j] + B[i]);
            }
        }
    }

    long long ans = NEG_INF;
    for (int i = sumW + 1; i < 2 * sumW + 1; i++) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << endl;
    return 0;
}