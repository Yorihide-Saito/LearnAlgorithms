#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<ll> sumA(N + 1, 0);
    for (int i = 0; i < N; i++) sumA[i + 1] = sumA[i] + A[i];

    ll ans = 0;
    const ll MOD = 998244353;
    for (int m = 0; m < M; m++) {
        ll x = B[m];
        ll low = lower_bound(A.begin(), A.end(), x) - A.begin();

        ll left = x * low - sumA[low];
        ll right = (sumA[N] - sumA[low]) - x * (N - low);

        ll add = (left + right) % MOD;
        if (add < 0) add += MOD;
        ans += add;
        ans %= MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}