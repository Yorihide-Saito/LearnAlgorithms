// [01-5] ABC231C Counting 2
// https://atcoder.jp/contests/abc231/tasks/abc231_c
// パターン: ソート+lower_bound
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

    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    while(q--) {
        int x;
        cin >> x;
        int it = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << n - (it) << endl;
    }
    return 0;
}
