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
    long long X_1, X_2, X_3;
    cin >> X_1 >> X_2 >> X_3;

    long long N = X_1 + X_2 + X_3 + 5;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    long long ans = 0;

    for (int i = 0; i <= X_1 && i <= X_2 + 1; i++) {
        long long waysChooseSlots = C(X_2 + 1, i);
        long long waysSplitOnes = C(X_1 - 1, i - 1);
        long long waysPlaceThrees = C(X_2 + X_3 - i, X_3);

        ans += waysChooseSlots * waysSplitOnes % MOD * waysPlaceThrees % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}