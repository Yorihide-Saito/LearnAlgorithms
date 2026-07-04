// ============================================================
// グリッドBFS (重みなし最短路)
// 使いどころ: マス目の最短手数。10分でバグなしで書けるように
// 計算量: O(HW)
// 代表問題: ABC151D, ABC168D
// 罠: 境界チェックの順序(範囲→壁→訪問済み) / queueに入れる時にdist確定
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H = 3, W = 3;
    vector<string> S = {"..#", "#.#", "#.."};
    int sy = 0, sx = 0;

    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;
    dist[sy][sx] = 0;
    q.emplace(sy, sx);
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue; // 範囲外
            if (S[ny][nx] == '#') continue;                       // 壁
            if (dist[ny][nx] != -1) continue;                     // 訪問済み
            dist[ny][nx] = dist[y][x] + 1;
            q.emplace(ny, nx);
        }
    }
    cout << dist[2][2] << '\n'; // 4
    return 0;
}
