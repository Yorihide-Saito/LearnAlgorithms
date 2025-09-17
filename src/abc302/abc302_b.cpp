#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int H, W; cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    const string T = "snuke";
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] != 's') continue; //起点はs
            for (int dir = 0; dir < 8; dir++) {
                int x = i, y = j;
                bool ok = true;
                for (int t = 0; t < 5; t++) {
                    int nx = i + dx[dir] * t;
                    int ny = j + dy[dir] * t;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                        ok = false;
                        break;
                    }
                    if (S[nx][ny] != T[t]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int t = 0; t < 5; t++) {
                        int nx = i + dx[dir] * t;
                        int ny = j + dy[dir] * t;
                        cout << (nx + 1) << " " << (ny + 1) << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}