#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
using i128 = __int128_t;

// abc146_c
// https://atcoder.jp/contests/abc146/tasks/abc146_c

static const ll INF = 1e9;

int main() {
    ll A, B, X;
    cin >> A >> B >> X;

    auto d = [&](ll x) -> ll {
        if (x == 0) return 1;
        if (x < 0) x = -x;
        int d = 0;
        while(x > 0) {
            x /= 10;
            d++;
        }
        return d;
    };

    ll low = -1, high = INF + 1;
    while(high - low > 1) {
        ll mid = (high + low) / 2;
        if((i128)A * mid + (i128)B * d(mid) > (i128)X) high = mid;
        else low = mid;
    }

    cout << max(0LL, low) << endl;
    return 0;
}