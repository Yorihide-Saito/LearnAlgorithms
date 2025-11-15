#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<utility>
using namespace std;
using ll = long long;

const ll INF = (1LL<<60);

int main() {
    ll N, X, Y; cin >> N >> X >> Y;
    vector<ll> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    auto f = [&](ll X, ll S, ll x) -> ll {
        return (X * x) + (Y * S) - (Y * x);
    };
    ll multiple = Y-X;

    ll L = -INF, R = INF;
    ll r = -1;
    for (int i = 0; i < A.size(); i++) {
        ll minRange = f(X, A[i], A[i]);
        ll maxRange = f(X, A[i], 0);
        // cout << minRange << " - " << maxRange << endl;
        L = max(L, minRange);
        R = min(R, maxRange);

        ll ri = (Y * A[i]) % multiple;
        if (r == -1) r = ri;
        else if (r != ri) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (L > R) {
        cout << -1 << endl;
        return 0;
    }

    ll pA = R - (((R - r) % multiple + multiple) % multiple);
    if (pA < L) {
        cout << -1 << endl;
        return 0;
    }
    // cout << pA << endl;

    ll count = 0;
    for (int i = 0; i < A.size(); i++) {
        count += (X * A[i] - pA) / (X - Y);
    }
    cout << count << endl;
    return 0;
}