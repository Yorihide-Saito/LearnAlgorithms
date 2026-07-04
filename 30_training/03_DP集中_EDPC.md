tags: #training #week4 #week5 #week6

# Week 4-6: DP集中 (Educational DP Contest)

## 学習目標

水色との最大の差はDPの引き出しの数。ABC464 DでDPを書けているので素養はある。ここでは「状態設計を自力でやる」訓練をする。

**毎問、コードを書く前に必ず紙に書くこと:**
1. `dp[i][j] = 〜` の日本語定義(これが一番大事)
2. 遷移式
3. 初期値と答えの場所

[EDPC](https://atcoder.jp/contests/dp) を使う。既存ノート [[DP]] に学んだパターンを追記していく。

## Week 4: 基本形

| # | 問題 | 学ぶこと |
|---|---|---|
| 1 | [A Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) | 最小コスト遷移の基本形 |
| 2 | [B Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b) | 遷移がK本になるだけ |
| 3 | [C Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | 状態に「直前の選択」を持つ(464Dと同型) |
| 4 | [D Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d) | ナップサック。dp[i][w]の定義を暗唱できるまで |
| 5 | [E Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e) | **軸の交換**(重さ→価値)。制約を見て軸を選ぶ |

## Week 5: 頻出形

| # | 問題 | 学ぶこと |
|---|---|---|
| 6 | [F LCS](https://atcoder.jp/contests/dp/tasks/dp_f) | 2系列DP+復元 |
| 7 | [H Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h) | グリッドDP+mod |
| 8 | [I Coins](https://atcoder.jp/contests/dp/tasks/dp_i) | 確率DP(doubleを恐れない) |
| 9 | [L Deque](https://atcoder.jp/contests/dp/tasks/dp_l) | 区間DP入門(l, rを状態に) |

## Week 6: 水色への武器

| # | 問題 | 学ぶこと |
|---|---|---|
| 10 | [ABC180E Traveling Salesman among Aerial Cities](https://atcoder.jp/contests/abc180/tasks/abc180_e) | bitDP(巡回セールスマン)。abc302_c で書いたbitDPの一般形 | 
| 11 | [O Matching](https://atcoder.jp/contests/dp/tasks/dp_o) | bitDP(マッチング) |
| 12 | [ABC154E Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e) | 桁DP入門(発展。厳しければWeek12に回してよい) |

> [!hint]- ヒント: bitDPの型
> `dp[S][v] = 訪問済み集合S、現在地vのときの最小コスト`。遷移は「Sに入っていないuへ進む」。`dp[S | 1 << u][u] = min(..., dp[S][v] + cost(v,u))`。

> [!hint]- ヒント: 桁DPの型
> `dp[i][smaller][状態] = 上からi桁決めて、既にNより小さいことが確定しているか、+問題固有の状態`。「Nちょうどに張り付いているか」の管理がすべて。

## 完了条件

- [ ] EDPC A〜E, F, H, I, L を白紙から再実装できる(1週間後の再実装ルール)
- [ ] bitDPのテンプレを [[DP]] ノートに自分の言葉で追記した
- [ ] dp定義を書かずにコードを書き始めない癖がついた
