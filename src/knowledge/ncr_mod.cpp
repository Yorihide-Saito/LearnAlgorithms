// ============================================================
// modpow / modinv / nCr (階乗前計算)
// 使いどころ: 「場合の数を mod で」ときたら初手でこれを貼る
// 計算量: 前計算 O(N)、クエリ O(1)
// 代表問題: ABC156D, ABC145D
// 罠: MOD は問題文で確認(998244353 か 1e9+7 か)
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll n, ll m = MOD) {
    ll r = 1; a %= m;
    while (n > 0) {
        if (n & 1) r = r * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return r;
}
ll modinv(ll a) { return modpow(a, MOD - 2); } // MODが素数のとき

struct Comb {
    vector<ll> fact, inv;
    Comb(int n) : fact(n + 1), inv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        inv[n] = modinv(fact[n]);
        for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;
    }
    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
    }
};

int main() {
    Comb c(100);
    cout << c.nCr(5, 2) << '\n';        // 10
    cout << modpow(2, 10) << '\n';      // 1024
    return 0;
}
