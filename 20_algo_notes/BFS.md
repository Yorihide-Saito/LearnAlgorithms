tags: #algorithm #graph

---

## 概要

幅優先探索（Breadth-First Search）。グラフや木を**近い順**に探索するアルゴリズム。最短経路問題で使用。

## 計算量

- 時間: `O(V + E)` (V: 頂点数, E: 辺数)
- 空間: `O(V)`

## 実装コード

```cpp
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// グリッド上のBFS（迷路の最短経路など）
int H, W;
vector<string> grid;
vector<vector<int>> dist;

void bfs(int sy, int sx) {
    queue<pair<int,int>> q;
    q.push({sy, sx});
    dist[sy][sx] = 0;

    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (grid[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

// グラフのBFS（隣接リスト表現）
vector<vector<int>> G;
vector<int> d;

void bfs_graph(int start) {
    queue<int> q;
    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int nv : G[v]) {
            if (d[nv] != -1) continue;
            d[nv] = d[v] + 1;
            q.push(nv);
        }
    }
}
```

## 使用例

- グリッド上の最短経路
- 重みなしグラフの最短距離
- 連結成分の探索
- 01-BFS（辺の重みが0/1のみ）

## 応用

**01-BFS**: 辺の重みが0または1のグラフで、dequeを使って高速に最短経路を求める

```cpp
deque<int> dq;
dq.push_front(start);
dist[start] = 0;

while (!dq.empty()) {
    int v = dq.front(); dq.pop_front();

    for (auto [nv, cost] : G[v]) {
        int nd = dist[v] + cost;
        if (dist[nv] <= nd) continue;
        dist[nv] = nd;

        if (cost == 0) dq.push_front(nv);
        else dq.push_back(nv);
    }
}
```
