// [03-3] EDPC C Vacation
// https://atcoder.jp/contests/dp/tasks/dp_c
// パターン: 直前の選択を状態に
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
    vector<int> dp(3, 0), ndp(3, 0);

    int a, b, c;
    cin >> a >> b >> c;
    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        ndp[0] = a + max(dp[1], dp[2]);
        ndp[1] = b + max(dp[0], dp[2]);
        ndp[2] = c + max(dp[0], dp[1]);
        dp = ndp;
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
