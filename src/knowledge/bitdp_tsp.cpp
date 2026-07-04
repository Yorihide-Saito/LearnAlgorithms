// ============================================================
// bitDP (巡回セールスマン型)
// 使いどころ: 「N≤17前後で訪問順を全部試したい」
//   dp[S][v] = 訪問済み集合S・現在地v の最小コスト
// 計算量: O(2^N × N^2)
// 代表問題: ABC180E, EDPC O
// 罠: dp配列の初期化はINF、開始状態だけ0 / SにvのbitがあるかチェックS
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

int main() {
    int N = 3;
    vector<vector<ll>> cost = {{0, 1, 10}, {1, 0, 2}, {10, 2, 0}};

    vector<vector<ll>> dp(1 << N, vector<ll>(N, INF));
    dp[1][0] = 0; // 都市0から出発
    for (int S = 1; S < (1 << N); S++) {
        for (int v = 0; v < N; v++) {
            if (dp[S][v] == INF || !(S >> v & 1)) continue;
            for (int u = 0; u < N; u++) {
                if (S >> u & 1) continue; // 訪問済み
                int T = S | 1 << u;
                dp[T][u] = min(dp[T][u], dp[S][v] + cost[v][u]);
            }
        }
    }
    // 全都市訪問して0に戻る
    ll ans = INF;
    for (int v = 1; v < N; v++)
        ans = min(ans, dp[(1 << N) - 1][v] + cost[v][0]);
    cout << ans << '\n'; // 13 (0->1->2->0)
    return 0;
}
