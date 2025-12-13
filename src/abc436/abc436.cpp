#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<vector<int>> g(H * W);
    vector<int> warp(26, -1);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h + 1 < H) {
                char c = S[h+1][w];
                if (c == '.') {
                    g[(W * h) + w].push_back((W * (h + 1)) + w);
                } else if(c == '#') {
                    continue;
                } else {
                    if (warp[c - 'a'] == -1) warp[c - 'a'] = (W * (h + 1)) + w;
                    else {
                        g[(W * (h + 1)) + w].push_back(warp[c - 'a']);
                        g[warp[c - 'a']].push_back((W * (h + 1)) + w);
                    }
                }
            }
            if (h - 1 >=0 ) {
                char c = S[h-1][w];
                if (c == '.') {
                    g[(W * h) + w].push_back((W * (h - 1)));
                } else if(c == '#') {
                    continue;
                } else {
                    if (warp[c - 'a'] == -1) warp[c - 'a'] = (W * (h - 1));
                    else {
                        g[(W * (h - 1)) + w].push_back(warp[c - 'a']);
                        g[warp[c - 'a']].push_back((W * (h - 1)) + w);
                    }
                }
            }
            if (w - 1 >=0) {
                char c = S[h+1][w-1];
                if (c == '.') {
                    g[(W * h) + w].push_back((W * (h)) + w - 1);
                } else if(c == '#') {
                    continue;
                } else {
                    if (warp[c - 'a'] == -1) warp[c - 'a'] = (W * (h)) + w - 1;
                    else {
                        g[(W * (h)) + w - 1].push_back(warp[c - 'a']);
                        g[warp[c - 'a']].push_back((W * (h)) + w - 1);
                    }
                }
            }
            if (w + 1 < W) {
                char c = S[h][w+1];
                if (c == '.') {
                    g[(W * h) + w].push_back((W * (h)) + w + 1);
                } else if(c == '#') {
                    continue;
                } else {
                    if (warp[c - 'a'] == -1) warp[c - 'a'] = (W * (h)) + w + 1;
                    else {
                        g[(W * (h)) + w + 1].push_back(warp[c - 'a']);
                        g[warp[c - 'a']].push_back((W * (h)) + w + 1);
                    }
                }
            }
        }
    }

    vector<int> dist(H * W, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 1;
    while(!q.empty()) {
        int c = q.front();q.pop();
        for (auto v : g[c]) {
            if (dist[v] == -1) {
                dist[v] = dist[c] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[H * W - 1] << endl;
    return 0;
}