// [02-3] ABC130D Enough Array
// https://atcoder.jp/contests/abc130/tasks/abc130_d
// パターン: 尺取り法
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
    for(auto &x : a) cin >> x;

    long long ans = 0, sum = 0;
    int r = 0;

    for (int l = 0; l < n; l++) {
        while(r < n && sum < k) {
            sum += a[r];
            r++;
        }
        if (sum >= k) ans += n - r + 1;
        sum -= s[l];
    }

    cout << ans << endl;
    return 0;
}
