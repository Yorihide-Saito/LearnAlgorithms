#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<climits>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N;
        cin >> N;
        string S;
        cin >> S;
        vector<long long> X(N), Y(N - 1);
        for (int i = 0; i < N; i++) cin >> X[i];
        for (int i = 0; i < N - 1; i++) cin >> Y[i];

        vector<long long> dp(2, 0), ndp(2, 0);

        auto cost = [&](long long i, int c) {
            return (c == (S[i] == 'R')) ? 0 : -X[i];
        };

        // S = 0, R = 1;
        dp[0] = cost(0, 0);
        dp[1] = cost(0, 1);

        for (int i = 1; i < N; i++) {
            ndp[0] = LLONG_MIN / 2;
            ndp[1] = LLONG_MIN / 2;
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    long long val = dp[j];
                    if (k == 0 && j == 1) val += Y[i - 1];
                    val += cost(i, k);
                    ndp[k] = max(ndp[k], val);
                }
            }
            dp = ndp;
        }
        cout << max(dp[0], dp[1]) << endl;
    }
    return 0;
}