// [01-2] ABC167C Skill Up
// https://atcoder.jp/contests/abc167/tasks/abc167_c
// パターン: bit全探索
//
// ---- 3行設計(書いてから実装する) ----
// ① データ構造: vector<int>
// ② ループ/遷移: for (int i = 0; i < (1 << n); i++)
// ③ 答え:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m;j ++) {
            cin >> a[i][j];
        }
    }

    int ans = INT32_MAX;
    for (int i = 0; i < (1 << n); i++) {
        int tmp = 0;
        vector<int> unds(m, 0);
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                tmp += c[j];
                for (int k = 0; k < m; k++) {
                    unds[k] += a[j][k];
                }
            }
        }
        bool isOk = true;
        for (int j = 0; j < m; j++) {
            if(unds[j] < x) {
                isOk  = false;
            }
        }
        if(isOk) ans = min(ans, tmp);
    }

    cout << (ans == INT32_MAX ? -1 : ans) << endl;
    return 0;
}
