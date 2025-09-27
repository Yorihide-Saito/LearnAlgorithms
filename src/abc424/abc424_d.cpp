#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int INF = 1e9;

int main () {
    int T; cin >> T;
    while(T--) {
        int H, W; cin >> H >> W;
        vector<string> S(H);
        for (int i = 0; i < H; i++) cin >> S[i];

        // Bitmasking
        vector<int> row(H, 0);
        for (int i = 0; i < H; i++) {
            int m =0;
            for (int j = 0; j < W; j++) {
                if (S[i][j] == '#') m |= (1<<j);
            }
            row[i] = m;
        }

        const int MAXM = 1 << W;

        vector<int> dp(MAXM, INF), ndp(MAXM, INF);
        // 1 行目：その行の黒ビットの部分集合だけ使える
        for (int C = 0; C < MAXM; C++) {
            if (C | row[0] != row[0]) continue;
            // bit count(1をカウントする)
            // https://cpprefjp.github.io/reference/bit/popcount.html
            int cost = __builtin_popcount(row[0] & ~C);
            dp[0] = cost;
        }

        for (int i = 1; i < H; i++) {
            // INF で ndp を埋める。
            // https://cpprefjp.github.io/reference/algorithm/fill.html
            fill(ndp.begin(), ndp.end(), INF);
            for (int P = 0; P < MAXM; P++) {
                if (dp[P] == INF) continue;
                for (int C = 0; C < MAXM; C++) {
                    // 変更ない場合
                    if (C | row[i] != row[i]) continue;
                    // P が今の行
                    // C が次の行
                    // 例えば、P=00011, C=00011の場合は、2x2になってしまうので変更不可
                    int X = P & C;
                    if ((X & (X << 1)) != 0) continue;
                    int cost = __builtin_popcount(row[i] & ~C);
                    ndp[C] = min(ndp[C], dp[P] + cost);
                }
            }
            // https://cpprefjp.github.io/reference/utility/swap.html
            dp.swap(ndp);
        }
        int ans = *min_element(dp.begin(), dp.end());
        cout << ans << endl;
    }
    return 0;
}