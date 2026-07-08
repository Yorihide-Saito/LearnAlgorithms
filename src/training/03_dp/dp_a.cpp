// [03-1] EDPC A Frog 1
// https://atcoder.jp/contests/dp/tasks/dp_a
// パターン: 基本DP
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
    vector<int> h(n);
    for (auto &x : h) cin >> x;

    vector<int> dp(n + 1, 0);
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++) {
        dp[i] = min(
            dp[i - 1] + abs(h[i] - h[i - 1]),
            dp[i - 2] + abs(h[i] - h[i - 2])
        );
    }
    cout << dp[n - 1] << endl;
    return 0;
}
