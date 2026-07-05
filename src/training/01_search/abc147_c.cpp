// [01-4] ABC147C HonestOrUnkind2
// https://atcoder.jp/contests/abc147/tasks/abc147_c
// パターン: bit全探索+整合性判定
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
    vector<vector<int>> x(n, vector<int>()), y(n, vector<int>());
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++) {
            int x_in, y_in;
            cin >> x_in >> y_in;
            x_in--;
            x[i].push_back(x_in);
            y[i].push_back(y_in);
        }
    }

    // 正直者のパターンを考える
    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        int isOk = true;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (bit >> i & 1) {
                for (int j = 0; j < a[i]; j++) {
                    if ((bit >> x[i][j] & 1) !=  y[i][j]) {
                        isOk = false;
                        break;
                    }
                }
                cnt++;
            }
        }
        if(isOk) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
