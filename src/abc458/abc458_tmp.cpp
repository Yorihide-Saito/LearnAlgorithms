#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
using ll = long long;
const long long MOD = 998244353;

long long fact[3000011], invFact[3000011];

long long modpow(long long a, long long e) {
    long long r = 1;
    while(e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long C(long long n, long long r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    long long X1, X2, X3;
    cin >> X1 >> X2 >> X3;

    long long N = X1 + X2 + X3 + 2;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long ans = 0;
    for (int i = 0; i <= X1 && i <= X2 + 1; i++) {
        long long a = C(X2 + 2, i);
        long long b = C(X1 - 1, i - 1);
        long long c = C(X2 + X3 - i, X2 - i);

        ans += a * b % MOD * c % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}