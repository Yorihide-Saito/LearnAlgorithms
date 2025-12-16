#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using ll = long long;

// abc114_e
// https://atcoder.jp/contests/abc144/tasks/abc144_e

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N, 0), F(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> F[i];

    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());

    auto ok = [&](ll mid) -> bool {
        ll need = 0;
        for (ll i = 0; i < N; i++) {
            ll a = A[i], f = F[i];
            ll maxA = mid / f;
            if (a > maxA) need += (a - maxA);
            if (need > K) return false;
        }
        return true;
    };

    ll low = -1, high = *max_element(A.begin(), A.end()) * *max_element(F.begin(), F.end());
    while(high - low > 1) {
        ll mid = (high + low) / 2;
        if(ok(mid)) high = mid;
        else low = mid;
    }

    cout << high << endl;
    return 0;
}