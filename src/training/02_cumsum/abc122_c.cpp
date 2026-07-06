// [02-1] ABC122C GeT AC
// https://atcoder.jp/contests/abc122/tasks/abc122_c
// パターン: 累積和
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
    string s;
    cin >> s;

    vector<int> sum(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        sum[i + 1] = sum[i];
        if(s[i] == 'A' && s[i+1] == 'C') {
            sum[i + 1]++;
        }
    }
    sum[n] = sum[n - 1];

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}
