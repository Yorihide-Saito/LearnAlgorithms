// [01-6] ABC077C Snuke Festival
// https://atcoder.jp/contests/abc077/tasks/arc084_a
// パターン: 各要素で二分探索
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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long acnt = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        long long ccnt = c.end() - upper_bound(c.begin(), c.end(), b[i]);

        ans += acnt * ccnt;
    }

    cout << ans << endl;
    return 0;
}
