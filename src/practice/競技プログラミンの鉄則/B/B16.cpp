#include<iostream>
using namespace std;

int N;
int H[100009];
int dp[100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];

    dp[1] = 0;
    dp[2] = H[2];

    for (int i = 2; i <= N; i++) {
        dp[i] = min(abs(dp[i-1] - H[i]), abs(dp[i-2] - H[i]));
    }
    cout << dp[N] << "\n";

    return 0;
}