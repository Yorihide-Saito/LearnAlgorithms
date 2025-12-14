#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (auto &row : S) cin >> row;

    auto id = [&](int r, int c) {
        return r * W + c;
    };

    // 各文字のワープの座標
    vector<vector<int>> pos(26);
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            char ch = S[r][c];
            if ('a' <= ch && ch <='z') {
                pos[ch - 'a'].push_back(id(r, c));
            }
        }
    }

    const int N = H * W;
    vector<int> dist(N, -1);
    queue<int> q;

    int st = 0;
    int gl = id(H - 1, W - 1);
    dist[st] = 0;
    q.push(st);

    vector<char> usedWarp(26, false);
    const int dr[4] = {1, -1, 0, 0};
    const int dc[4] = {0, 0, 1, -1};

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int r = v / W;
        int c = v % W;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (S[nr][nc] == '#') continue;
            int to = id(nr, nc);
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }

        char ch = S[r][c];
        if ('a' <= ch && ch <= 'z') {
            int t = ch - 'a';
            if (!usedWarp[t]) {
                usedWarp[t] = true;
                for (int to : pos[t]) {
                    if (dist[to] == -1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
    }
    cout << dist[gl] << endl;
    return 0;
}