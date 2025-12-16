#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

// abc119_d
// https://atcoder.jp/contests/abc119/tasks/abc119_d

static const ll INF = 1LL << 58;

int main() {
    int A ,B, Q; cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    for (int i = 0; i < A; i++) cin >> s[i];
    for (int i = 0; i < B; i++) cin >> t[i];

    s.push_back(INF); s.push_back(-INF);
    t.push_back(INF); t.push_back(-INF);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    auto formar = [&](const vector<ll>& v, ll x) -> ll {
        return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
    };

    auto latter = [&](const vector<ll>& v, ll x) -> ll {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    };

    while(Q--) {
        ll x; cin >> x;
        ll res = INF;

        for (int i = 0; i < 2; i++) {
            ll first = (i ? s[formar(s, x)] : s[latter(s, x)]);
            for (int j = 0; j < 2; j++) {
                ll second = (j ? t[formar(t, x)] : t[latter(t, x)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }

        for (int i = 0; i < 2; i++) {
            ll first = (i ? t[formar(t, x)] : t[latter(t, x)]);
            for (int j = 0; j < 2; j++) {
                ll second = (j ? s[formar(s, x)] : s[latter(s, x)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }
        cout << res << endl;
    }
    return 0;
}