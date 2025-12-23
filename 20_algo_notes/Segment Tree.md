tags: #algorithm #data-structure

---

## 概要

セグメント木（Segment Tree）。**区間クエリと1点更新を O(log N) で処理**するデータ構造。RMQ（Range Minimum Query）など。

## 計算量

- 構築: `O(N)`
- 更新: `O(log N)`
- クエリ: `O(log N)`

## 実装コード

### 基本的なセグメント木（RMQ）

```cpp
template<typename T>
struct SegmentTree {
    int n;
    vector<T> dat;
    T e;  // 単位元（minならINF、maxなら-INF、sumなら0）

    SegmentTree(int n_, T e_) : e(e_) {
        n = 1;
        while (n < n_) n *= 2;
        dat.assign(2 * n - 1, e);
    }

    // 演算（min, max, sum など）
    T op(T a, T b) {
        return min(a, b);  // RMQの場合
    }

    // i番目の値をxに更新
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;

        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // 区間 [l, r) のクエリ
    T query(int l, int r) {
        return query_sub(l, r, 0, 0, n);
    }

    T query_sub(int l, int r, int k, int cl, int cr) {
        if (r <= cl || cr <= l) return e;
        if (l <= cl && cr <= r) return dat[k];

        T vl = query_sub(l, r, k * 2 + 1, cl, (cl + cr) / 2);
        T vr = query_sub(l, r, k * 2 + 2, (cl + cr) / 2, cr);
        return op(vl, vr);
    }
};
```

### 使い方

```cpp
const int INF = 1e9;

// 最小値を求めるセグメント木
SegmentTree<int> seg(N, INF);

// 初期化
for (int i = 0; i < N; i++) {
    seg.update(i, A[i]);
}

// i番目をxに更新
seg.update(i, x);

// 区間 [l, r) の最小値を取得
int min_val = seg.query(l, r);
```

## よくある演算の単位元

| 演算 | 単位元 | op(a, b) |
|------|--------|----------|
| min  | INF    | min(a, b) |
| max  | -INF   | max(a, b) |
| sum  | 0      | a + b     |
| gcd  | 0      | gcd(a, b) |
| 積   | 1      | a * b     |

## 応用

### 遅延評価セグメント木（Lazy Segment Tree）

区間更新と区間クエリを両方 O(log N) で処理できる。実装は複雑だが、ACLを使うと簡単。

```cpp
#include <atcoder/lazysegtree>
using namespace atcoder;

// 区間加算・区間和のlazysegtree
using S = long long;
using F = long long;

S op(S a, S b) { return a + b; }
S e() { return 0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
```

## 注意点

- 配列サイズは2のべき乗に切り上げる
- 単位元を間違えないように（min問題ならINF）
- 0-indexed で実装することが多い
- AC Libraryの `segtree` を使うと実装が楽
