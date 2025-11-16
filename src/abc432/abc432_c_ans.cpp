#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;

int main() {
    ll N, X, Y; cin >> N >> X >> Y;

    ll d = Y - X;
    ll g = gcd(X, d);
    ll k = d / g;

    vector<ll> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    ll sumA = A[0];
    ll L = X * A[0];
    ll R = Y * A[0];

    for (int i = 1; i < N; i++) {
        sumA += A[i];
        if ((A[i] - A[0]) % k != 0) {
            cout << -1 << endl;
            return 0;
        }

        L = max(L, X * A[i]);
        R = min(R, Y * A[i]);
    }

    if (L > R) {
        cout << -1 << endl;
        return 0;
    }

    ll r = (X * A[0] % d);
    ll t = ((R - r) % d + d) % d;
    ll w = R - t;

    if (w < L) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (w - X * A[i]) / d;
    }
    cout << ans << endl;
    return 0;
}