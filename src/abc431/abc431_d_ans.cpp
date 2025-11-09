#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
using namespace std;

const long long NEG_INF = -(1LL << 60);

int main() {
    int N; cin >> N;
    vector<long long> w(N + 1, 0), diffH2B(N + 1, 0);
    long long sumW = 0, sumB = 0;
    long long W, H, B;
    for (int i = 1; i <= N; i ++) {
        cin >> W >> H >> B;
        sumW += W;
        sumB += B;
        if(H - B > 0) {
            diffH2B[i] = H - B;
            w[i] = W;
        }
    }

    int halfSumW = (int)sumW / 2 + 1;
    int sizeDiffH2B = diffH2B.size();

    vector<long long> dp(halfSumW, NEG_INF), ndp(halfSumW, NEG_INF);
    dp[0] = 0;

    for (int i = 1; i < sizeDiffH2B; i++) {
        fill(ndp.begin(), ndp.end(), NEG_INF);
        for (int j = 0; j < halfSumW; j++){
            if (dp[j] == NEG_INF) continue;
            ndp[j] = max(ndp[j], dp[j]);
            if (j + (int)w[i] < halfSumW) {
                ndp[j + (int)w[i]] = max(ndp[j + w[i]], dp[j] + diffH2B[i]);
            }
        }
        dp.swap(ndp);
    }

    long long ans = NEG_INF;
    for (int i = 0; i < halfSumW; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans + sumB << endl;
    return 0;
}