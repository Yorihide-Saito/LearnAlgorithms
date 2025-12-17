#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

// abc205_d
// https://atcoder.jp/contests/abc205/tasks/abc205_d

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N, 0);
    for (auto& a : A) cin >> a;

    auto missing = [&](ll x) -> ll {
        ll cnt = upper_bound(A.begin(), A.end(), x) - A.begin();
        return x - cnt;
    };

    while(Q--) {
        ll K; cin >> K;

        ll low = 0;
        ll high = (ll)2e18;
        while(high - low > 1) {
            ll mid = (high + low) / 2;
            if (missing(mid) >= K) high = mid;
            else low = mid;
        }
        cout << high << endl;
    }
    return 0;
}