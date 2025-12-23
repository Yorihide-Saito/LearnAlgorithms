tags: #algorithm #graph

---

## 概要

深さ優先探索（Depth-First Search）。グラフや木を**深い方向**に探索するアルゴリズム。全探索や経路列挙で使用。

## 計算量

- 時間: `O(V + E)` (V: 頂点数, E: 辺数)
- 空間: `O(V)` (再帰の深さ)

## 実装コード

```cpp
#include<iostream>
#include<vector>
using namespace std;

// グリッド上のDFS
int H, W;
vector<string> grid;
vector<vector<bool>> visited;

void dfs(int y, int x) {
    if (y < 0 || y >= H || x < 0 || x >= W) return;
    if (grid[y][x] == '#') return;
    if (visited[y][x]) return;

    visited[y][x] = true;

    // 4方向に探索
    dfs(y-1, x);
    dfs(y, x+1);
    dfs(y+1, x);
    dfs(y, x-1);
}

// グラフのDFS（隣接リスト表現）
vector<vector<int>> G;
vector<bool> vis;

void dfs_graph(int v) {
    vis[v] = true;

    for (int nv : G[v]) {
        if (vis[nv]) continue;
        dfs_graph(nv);
    }
}

// 戻り値を返すDFS（例：経路数カウント）
int dfs_count(int v, int goal) {
    if (v == goal) return 1;
    if (vis[v]) return 0;

    vis[v] = true;
    int cnt = 0;

    for (int nv : G[v]) {
        cnt += dfs_count(nv, goal);
    }

    return cnt;
}
```

## 使用例

- 連結成分の探索
- サイクル検出
- トポロジカルソート
- 全探索（順列、組み合わせ）

## 応用

**順列の全探索**:

```cpp
vector<int> perm;
vector<bool> used(N, false);

void dfs_perm(int depth) {
    if (depth == N) {
        // permを使った処理
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        used[i] = true;
        perm.push_back(i);

        dfs_perm(depth + 1);

        perm.pop_back();
        used[i] = false;
    }
}
```

**部分集合の全探索**:

```cpp
void dfs_subset(int i, vector<int> &subset) {
    if (i == N) {
        // subsetを使った処理
        return;
    }

    // i番目を含めない
    dfs_subset(i + 1, subset);

    // i番目を含める
    subset.push_back(A[i]);
    dfs_subset(i + 1, subset);
    subset.pop_back();
}
```
