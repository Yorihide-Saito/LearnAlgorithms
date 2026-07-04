// ============================================================
// 二次元いもす法 (矩形領域への一括加算)
// 使いどころ: 「長方形領域に+1を大量に→最後に各マスの値」
// 計算量: O(HW + N)
// 代表問題: 典型90-028, ABC183D(1次元)
// 罠: 座標が「マス」か「点」か図を描いてから。半開区間 [y1,y2)×[x1,x2) で統一
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H = 4, W = 4;
    vector<vector<ll>> imos(H + 1, vector<ll>(W + 1, 0));

    // 矩形 [y1,y2) x [x1,x2) に +1 (4点更新)
    auto add = [&](int y1, int x1, int y2, int x2) {
        imos[y1][x1]++;
        imos[y1][x2]--;
        imos[y2][x1]--;
        imos[y2][x2]++;
    };
    add(0, 0, 2, 2);
    add(1, 1, 3, 3);

    for (int y = 0; y <= H; y++)                       // 横に累積
        for (int x = 1; x <= W; x++) imos[y][x] += imos[y][x - 1];
    for (int x = 0; x <= W; x++)                       // 縦に累積
        for (int y = 1; y <= H; y++) imos[y][x] += imos[y - 1][x];

    cout << imos[1][1] << '\n'; // 2 (重なり部分)
    return 0;
}
