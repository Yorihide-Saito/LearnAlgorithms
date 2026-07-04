// ============================================================
// 答えで二分探索 (判定問題化)
// 使いどころ: 「最大値の最小化」「◯◯できる最大のX」
//   check(x) = 「答えを x としたとき達成可能か?」に単調性があれば使える
// 計算量: O(判定 × log(答えの範囲))
// 代表問題: ABC174E, ABC146C, ABC023D
// 罠: ok/ng の初期値は「絶対に true / 絶対に false」な値にする
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 例: ABC174E 丸太A を K回切って最長を x 以下にできるか
    vector<ll> A = {7, 9};
    ll K = 3;

    auto check = [&](ll x) {
        ll cnt = 0;
        for (ll a : A) cnt += (a + x - 1) / x - 1; // ceil(a/x) - 1 回
        return cnt <= K;
    };

    ll ok = 2e9, ng = 0; // check(ok)=true / check(ng)=false を維持
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n'; // 4
    return 0;
}
