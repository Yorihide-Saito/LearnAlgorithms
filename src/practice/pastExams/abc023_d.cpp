#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

// abc023_d
// https://atcoder.jp/contests/abc023/tasks/abc023_d

static const ll INF = (1LL<<60);

int main() {
    int N; cin >> N;
    vector<ll> h(N, 0), s(N, 0);
    for (int i = 0 ; i < N; i++) {
        cin >> h[i] >> s[i];
    }

    auto ok = [&](ll mid) -> bool {
        vector<ll> t(N, 0);
        for (int i = 0; i < N; i++) {
            if (mid < h[i]) return false;
            else t[i] = (mid - h[i]) / s[i];
        }

        sort(t.begin(), t.end());
        for (int i = 0; i < N; i++) {
            if (t[i] < i) return false;
        }
        return true;
    };


    ll low = -1, high = INF;
    while(high - low > 1) {
        ll mid = (high + low) / 2;
        (ok(mid) ? high : low) = mid;
    }
    cout << high << endl;
    return 0;
}