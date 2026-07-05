// [01-3] ABC128C Switches
// https://atcoder.jp/contests/abc128/tasks/abc128_c
// パターン: bit全探索
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(n, 0));
    vector<int> k(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int tmp = 0;
            cin >> tmp;
            s[i][--tmp] = 1;
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        int isOk = true;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((bit >> j & 1) && s[i][j]) {
                    cnt++;
                }
            }
            if (cnt % 2 != p[i]) {
                isOk = false;
                break;
            }
        }
        if(isOk) ans++;
    }
    cout << ans << endl;
    return 0;
}
