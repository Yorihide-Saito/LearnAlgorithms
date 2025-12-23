tags: #algorithm #data-structure

---

## 概要

Union-Find（素集合データ構造）。グループの**結合**と**同じグループか判定**を高速に行うデータ構造。

## 計算量

- union: `O(α(N))` ≈ `O(1)` (α: アッカーマン関数の逆関数)
- find: `O(α(N))` ≈ `O(1)`

## 実装コード

```cpp
struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n), siz(n, 1) {
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);  // 経路圧縮
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;

        // union by size
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};
```

## 使い方

```cpp
int N = 10;
UnionFind uf(N);

// 0と1を結合
uf.unite(0, 1);

// 1と2を結合
uf.unite(1, 2);

// 0と2は同じグループか？
cout << uf.same(0, 2) << endl;  // 1 (true)

// 0のグループのサイズ
cout << uf.size(0) << endl;  // 3
```

## 使用例

- グラフの連結成分判定
- クラスカル法（最小全域木）
- 動的連結性判定
- 等価関係の管理

## 応用

**重み付きUnion-Find**: 各要素に親からの重みを持たせる

```cpp
struct WeightedUnionFind {
    vector<int> par;
    vector<int> diff_weight;  // 親との重みの差分

    WeightedUnionFind(int n) : par(n), diff_weight(n, 0) {
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    int weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    // weight(y) - weight(x) = w となるように結合
    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;

        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
};
```
