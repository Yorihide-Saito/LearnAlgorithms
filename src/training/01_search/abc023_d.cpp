// [01-9] ABC023D 射撃王
// https://atcoder.jp/contests/abc023/tasks/abc023_d
// パターン: 答えで二分探索+貪欲判定
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
    long long n;
    cin >> n;
    vector<long long> h(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> s[i];
    }

    long long ok = 1LL << 60, ng = -1;
    auto check = [&] (long long mid) {
        vector<long long > time(n, 0);
        for (int i = 0; i < n; i++) {
            if (mid < h[i]) return false;

            long long diff = mid - h[i];
            long long sec = diff / s[i];
            time[i] = sec;
        }
        sort(time.begin(), time.end());
        for (int i = 0; i < n; i++) {
            if (time[i] < (long long)i) {
                return false;
            }
        }
        return true;
    };
    while(ok - ng > 1) {
        long long mid = (ng + ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;
    return 0;
}
