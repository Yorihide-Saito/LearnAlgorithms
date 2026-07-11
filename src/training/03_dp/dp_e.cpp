// [03-5] EDPC E Knapsack 2
// https://atcoder.jp/contests/dp/tasks/dp_e
// パターン: 軸の交換
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

    int N;
    long long W;
    cin >> N >> W;

    const int MAX_V = 100000;
    const long long INF = 1LL << 60;
    vector<long long> dp(MAX_V + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        long long w, v;
        cin >> w >> v;
        vector<long long> ndp = dp;
        for (int i = 0; i + v <= MAX_V; i++) {
            if(dp[i] == INF) continue;
            ndp[i + v] = min(ndp[i + v], dp[i] + w);
        }
        dp = move(ndp);
    }

    long long ans = 0;
    for (long long i = 0; i <= MAX_V; i++) {
        if (dp[i] == INF) continue;
        if (dp[i] <= W) {
            ans = max(i, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
