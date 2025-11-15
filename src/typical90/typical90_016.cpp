#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    ll A, B, C; cin >> A >> B >> C;
    vector<ll> v = {A, B, C};
    sort(v.rbegin(), v.rend());
    ll a = v[0], b = v[1], c = v[2];

    int ans = 10000;
    const ll i_max = min<ll>(9999, N / a);
    for (int i = 0; i <= i_max; i++) {
        if (i >= ans) break;
        ll rem_1 = N - a * i;

        const ll j_max = min<ll>(9999 - i, rem_1 / b);
        for (ll j = 0; j <= j_max; j++) {
            if (i + j >= ans) break;
            ll rem_2 = rem_1 - b * j;
            if (rem_2 % c == 0) {
                ans = min(ans, (int)(i + j + rem_2 / c));
            }
        }
    }

    cout << ans << endl;
    return 0;
}