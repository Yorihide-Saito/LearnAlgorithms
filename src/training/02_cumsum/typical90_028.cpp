// [02-5] 典型90-028 Cluttered Paper
// https://atcoder.jp/contests/typical90/tasks/typical90_ab
// パターン: 二次元いもす法
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
    vector<vector<int>> grid(1002, vector<int>(1002, 0));
    for (int i = 0; i < n; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        grid[lx][ly] += 1;
        grid[lx][ry] -= 1;
        grid[rx][ly] -= 1;
        grid[rx][ry] += 1;

    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            grid[i][j + 1] += grid[i][j];
        }
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            grid[j + 1][i] += grid[j][i];
        }
    }

    vector<int> ans(n + 1, 0);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            ans[grid[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
