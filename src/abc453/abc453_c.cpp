#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        L[i] *= 2;
    }

    map<ll, int> dp;
    dp[1] = 0;

    for (int i = 0; i < N; i++) {
        map<ll, int> ndp;

        for (auto [x, cnt] : dp) {
            // positive
            ll nx_1 = x + L[i];
            int add_1 = 0;
            if ((x > 0 && nx_1 < 0) || (x < 0 && nx_1 > 0)) {
                add_1 = 1;
            }
            if (!ndp.count(nx_1) || ndp[nx_1] < cnt + add_1) {
                ndp[nx_1] = cnt + add_1;
            }

            // negative
            ll nx_2 = x - L[i];
            int add_2 = 0;
            if ((x > 0 && nx_2 < 0) || (x < 0 && nx_2 > 0)) {
                add_2 = 1;
            }
            if (!ndp.count(nx_2) || ndp[nx_2] < cnt + add_2) {
                ndp[nx_2] = cnt + add_2;
            }
        }

        dp = move(ndp);
    }

    int ans = 0;
    for (auto [x, cnt] : dp) {
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}