#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

const ll INF = 1e16;

int main() {
    ll n, l, k;
    cin >> n >> l;
    cin >> k;
    vector<ll> a(n + 2, 0);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = l;

    ll left = -1, right = l + 1;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        ll prev = 0, count = 0;
        for (ll i = 1; i <= n + 1; i++) {
            if (a[i] - a[prev] >= mid) {
                prev = i;
                count++;
            }
        }

        if(count >= k + 1) left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}