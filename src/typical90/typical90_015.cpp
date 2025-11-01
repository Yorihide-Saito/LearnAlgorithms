#include<iostream>
#include<vector>
using namespace std;

const int MOD = 1'000'000'007;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    int N; cin >> N;
    vector<long long> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[N] = modpow(fact[N], MOD-2);
    for (int i = N; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;

    auto nCk = [&](int n, int k) -> long long {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    };


    for (int k = 1; k <= N; k++) {
        long long ans = 0;
        int mmax = (N + k - 1) / k;
        for (int m = 1; m <= mmax; m++) {
            int n = N - (k - 1) * (m - 1);
            ans += nCk(n, m);
            if (ans >= MOD) ans -= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}