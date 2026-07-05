// [01-7] ABC146C Buy an Integer
// https://atcoder.jp/contests/abc146/tasks/abc146_c
// パターン: 答えで二分探索
//
// ---- 3行設計(書いてから実装する) ----
// ① データ構造:
// ② ループ/遷移:
// ③ 答え:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, b, x;
    cin >> a >> b >> x;

    long long ok = 0, ng = 1e9 + 1;
    auto d = [&] (long long x) {
        long long ans = 0;
        while(x > 0) {
            x = x / 10;
            ans++;
        }
        return ans;
    };
    auto check = [&] (long long mid) {
        return x >= (a * mid) + (b * d(mid));
    };
    while(ng - ok > 1) {
        long long mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;
    return 0;
}
