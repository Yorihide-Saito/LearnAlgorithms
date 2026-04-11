#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

struct Prev {
    int p_h, p_w, p_dir;
};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int s_h = 0, s_w = 0;
    int g_h = 0, g_w = 0;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == 'S') {
                s_h = h;
                s_w = w;
            }
            if (S[h][w] == 'G') {
                g_h = h;
                g_w = w;
            }
        }
    }

    const int dh[4] = {-1, 1, 0, 0};
    const int dw[4] = {0, 0, -1, 1};

    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(4, 0)));
    vector<vector<vector<Prev>>> parent(H, vector<vector<Prev>>(W, vector<Prev>(4, {0, 0, 0})));

    auto bfs = [&]() -> Prev{
        queue<Prev> q;
        for (int dir = 0; dir < 4; dir++) {
            int n_h = s_h + dh[dir];
            int n_w = s_w + dw[dir];
            if (0 > n_h || n_h >= H || 0 > n_w || n_w >= W) continue;
            if (S[n_h][n_w] == '#') continue;

            if (!visited[n_h][n_w][dir]) {
                visited[n_h][n_w][dir] = 1;
                parent[n_h][n_w][dir] = {s_h, s_w, 0};
                q.push({n_h, n_w, dir});
            }
        }

        while(!q.empty()) {
            auto [h, w, dir] = q.front();
            q.pop();

            if (h == g_h && w == g_w) return {h, w, dir};

            vector<int> next_dirs;

            // 進む方向の方針決め
            char c = S[h][w];
            if (c == '.' || c == 'S' || c == 'G') {
                next_dirs = {0, 1, 2, 3};
            } else if (c == 'o') {
                next_dirs = {dir};
            } else if (c == 'x') {
                for (int n_dir = 0; n_dir < 4; n_dir++) {
                    if (n_dir != dir) next_dirs.push_back(n_dir);
                }
            }

            for (int n_dir : next_dirs) {
                int n_h = h + dh[n_dir];
                int n_w = w + dw[n_dir];

                if (0 > n_h || n_h >= H || 0 > n_w || n_w >= W) continue;
                if (S[n_h][n_w] == '#') continue;
                if (visited[n_h][n_w][n_dir]) continue;

                visited[n_h][n_w][n_dir] = 1;
                parent[n_h][n_w][n_dir] = {h, w, dir};
                q.push({n_h, n_w, n_dir});
            }
        }

        return {-1, -1, -1};
    };

    Prev tmp = bfs();
    int t_h = tmp.p_h;
    int t_w = tmp.p_w;
    int t_dir = tmp.p_dir;

    const char dc[4] = {'U', 'D', 'L', 'R'};

    vector<char> ans;
    while(!(t_h == s_h && t_w == s_w)) {
        ans.push_back(dc[t_dir]);
        Prev p = parent[t_h][t_w][t_dir];
        t_h = p.p_h;
        t_w = p.p_w;
        t_dir = p.p_dir;
    }

    reverse(ans.begin(), ans.end());

    for (char c : ans) cout << c;
    cout << endl;

    return 0;
}