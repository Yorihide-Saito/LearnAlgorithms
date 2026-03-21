#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
using ll = long long;

int main() {
    int H ,W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<vector<int>> visited(H, vector<int>(W, 0));
    int ans = 0;

    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};

    // 全ての白マスにおいてBFS
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.' && !visited[i][j]) {
                visited[i][j] = 1;
                bool isOk = true;

                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    if (x == 0 || x == H - 1 || y == 0 || y == W - 1) {
                        isOk = false;
                    }

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + di[dir];
                        int ny = y + dj[dir];

                        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                        if (visited[nx][ny]) continue;
                        if (S[nx][ny] == '#') continue;

                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if (isOk) ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
