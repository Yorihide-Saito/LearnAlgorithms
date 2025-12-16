#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ll N, L, K;
    cin >> N >> L;
    cin >> K;
    vector<ll> A(N, 0);
    for (auto &a : A) cin >> a;

    auto ok = [&](int mid) -> bool {
        ll num = 0;
        ll pre = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] - pre >= mid) {
                num++;
                pre = A[i];
            }
        }
        if (L - pre >= mid) num++;
        return (num >= K + 1);
    };

    ll l = -1, r = L + 1;
    while(r - l > 1) {
        ll mid = (l + r) / 2;
        (ok(mid) ? l : r) = mid;
    }
    cout << l << endl;
    return 0;
}