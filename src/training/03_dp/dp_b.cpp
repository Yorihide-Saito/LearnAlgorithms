// [03-2] EDPC B Frog 2
// https://atcoder.jp/contests/dp/tasks/dp_b
// パターン: 基本DP(遷移K本)
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

    int n, k;
    cin >> n >> k;
    vector<int> h(n, 0);
    for (auto &x : h) cin >> x;

    const int INF = 1e9;
    vector<int> dp(n + k, INF);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}
