// [03-6] EDPC F LCS
// https://atcoder.jp/contests/dp/tasks/dp_f
// パターン: 2系列DP+復元
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

    string s, t;
    cin >> s >> t;

    int ssiz = s.size();
    int tsiz = t.size();

    vector<vector<int>> dp(3001, vector<int>(3001, 0));
    for (int i = 1; i <= ssiz; i++) {
        for (int j = 1; j <= tsiz; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans;
    int i = ssiz, j = tsiz;
    while(i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
