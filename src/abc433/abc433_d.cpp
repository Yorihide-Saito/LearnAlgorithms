#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0 ; i < N; i++) cin >> A[i];

    vector<ll> p10(11);
    p10[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p10[i] = (p10[i - 1] * 10) % M;
    }

    vector<unordered_map<ll, ll>> cnt(11);

    for (int i = 0; i < N; i++) {
        ll a = A[i] % M;
        for (int len = 1; len <= 10; len++) {
            ll v = (a * p10[len]) % M;
            cnt[len][v]++;
        }
    }

    auto digits = [](ll x) -> int {
        int d = 0;
        while(x > 0) { x /= 10; d++; }
        return d;
    };

    ll ans = 0;
    for (int j = 0; j < N; j++) {
        int len = digits(A[j]);
        ll need = (M - (A[j] % M)) % M;
        auto it = cnt[len].find(need);
        if (it != cnt[len].end()) ans += it -> second;
    }

    cout << ans << endl;
    return 0;
}