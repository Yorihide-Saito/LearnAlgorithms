// [03-8] EDPC I Coins
// https://atcoder.jp/contests/dp/tasks/dp_i
// パターン: 確率DP
//
// ---- 3行設計(書いてから実装する) ----
// ① データ構造:
// ② ループ/遷移:
// ③ 答え:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;
    for (int i = 0; i < n; i++) {
        double p;
        cin >> p;

        vector<double> ndp(n + 1, 0.0);
        for (int j = 0; j <= i; j++) {
            ndp[j] += dp[j] * (1.0 - p);
            ndp[j + 1] += dp[j] * p;
        }

        dp = move(ndp);
    }

    double ans = 0.0;
    for (int i = n / 2 + 1; i <= n; i++) {
        ans += dp[j];
    }

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}
