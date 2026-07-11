// [03-4] EDPC D Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d
// パターン: ナップサック
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

    int N, W;
    cin >> N >> W;
    vector<long long> dp(W + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;

        vector<long long> ndp = dp;
        for (int j = 0; j < W + 1; j++) {
            if (dp[j] > -1 && j + w < W + 1) {
                ndp[j + w] = max(dp[j] + v, ndp[j + w]);
            }
        }
        dp = ndp;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
