// [02-4] ABC098D Xor Sum 2
// https://atcoder.jp/contests/abc098/tasks/arc098_d
// パターン: 尺取り法+XOR
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
    vector<long long> a(n, 0);
    for(auto &x : a) cin >> x;

    long long ans = 0, sum = 0, xr = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while(r < n && sum + a[r] == (xr ^ a[r])) {
            sum += a[r];
            xr ^= a[r];
            r++;
        }

        ans += r - l;
        sum -= a[l];
        xr ^= a[l];
    }

    cout << ans << endl;

    return 0;
}
