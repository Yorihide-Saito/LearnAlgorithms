#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int a[109][19], dp[109][1024];


int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = 1'000'000'000;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < (1 << N); j++) {
            int already[19];
            for (int k = 1; k <= N; k++) {
                if ((j / (1 << (k-1))) % 2 == 0) already[k] = 0;
                else already[k] = 1;
            }

            int v = 0;
            for (int k = 1; k <= N; k++) {
                if (already[k] == 1 || a[i][k] == 1) v += (1 << (k-1));
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][v] = min(dp[i][v], dp[i-1][j] + 1);
        }
    }

    if (dp[M][(1 << N) - 1] == 1'000'000'000) cout << "-1" << endl;
    else cout << dp[M][(1 << N) - 1] << endl;
    return 0;
}