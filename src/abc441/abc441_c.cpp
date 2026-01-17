#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // 累積和
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i+1] = pref[i] + a[i];

    // アルコールの入った最小数の時点で、x を越えられない場合はそもそも達成不可。
    if (pref[k] < x) {
        cout << -1 << endl;
        return 0;
    }

    for (ll j = n - k + 1; j <= n; j++) {
        // 最低数の座標 m
        ll m = j - (n - k);
        // 現在の座標
        ll start = n - j;
        ll sum_alc = pref[start + m] - pref[start];
        if (sum_alc >= x) {
            cout << j << endl;
            return 0;
        }
    }
    return 0;
}
