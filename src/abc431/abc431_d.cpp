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

    const int OFF = (int)sumW;
    const int M = (int) 2 * sumW + 1;
    vector<long long> dp(M + 1, NEG_INF), ndp( + 1, NEG_INF);
    dp[OFF] = 0;

    for (int i = 1; i <= N; i++) {
        fill(ndp.begin(), ndp.end(), NEG_INF);
        for (int j = 0; j <= M; j++) {
            if (dp[j] == NEG_INF) continue;

            if (j + W[i] < M) {
                ndp[j + W[i]] = max(ndp[j + W[i]], dp[j] + H[i]);
            }
            if (j - W[i] >= 0) {
                ndp[j - W[i]] = max(ndp[j - W[i]], dp[j] + B[i]);
            }
        }
        dp.swap(ndp);
    }

    long long ans = NEG_INF;
    for (int i = 0; i < OFF; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}