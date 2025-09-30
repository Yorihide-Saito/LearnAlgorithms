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
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n+1] = l;

    ll left = -1, right = INF;
    while (right - left > 1) {
        ll prev = 0, count = 0;
        ll mid = (right + left) / 2;
        for (int i = 1; i <= n + 1; i++) {
            if (mid <= a[i] - a[prev]) {
                count++;
                prev = i;
            }
        }
        if (count > k) left = mid;
        else right = mid;
    }

    cout << left << endl;
    return 0;
}