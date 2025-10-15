#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long MOD = 1e9 + 7;

int main() {
    int N; cin >> N;
    string S; cin >> S;

    const string target = "atcoder";
    int M = target.size();
    vector<vector<long long>> dp(N+1, vector<long long>(M + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0 && S[i - 1] == target[j - 1]) dp[i][j] = (dp[i-1][j-1] + dp[i][j]) % MOD;
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}