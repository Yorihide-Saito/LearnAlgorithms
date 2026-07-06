// [01-8] ABC174E Logs
// https://atcoder.jp/contests/abc174/tasks/abc174_e
// パターン: 答えで二分探索(最大値の最小化)
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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long ng = 0, ok = 1e9;
    auto check = [&] (long long mid) {
        long long need = 0;
        for (int i = 0; i < n; i++) {
            need += (a[i] - 1) / mid;
        }
        return need <= k;
    };
    while(ok - ng > 1) {
        long long mid = (ok + ng) / 2;
        (check(mid)? ok : ng) = mid;
    }

    cout << ok << endl;

    return 0;
}
