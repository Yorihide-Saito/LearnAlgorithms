#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
using namespace std;
const int INF = 1e9;
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    long long H, W;
    cin >> H >> W;
    vector<string> S;
    for (long long i = 0; i < H; i++) {
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }

    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<long long, long long>> q;

    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        pair<long long, long long> c = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            long long x = c.second+ dx[i];
            long long y = c.first + dy[i];
            if (x >= 0 && y >= 0 && x < W && y < H) {
                if (dist[y][x] == INF) {
                    q.push({y, x});
                    dist[y][x] = dist[c.first][c.second] + 1;
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (dist[i][j] % 2 == 0) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}