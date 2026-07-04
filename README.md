# LearnAlgorithms

競技プログラミングのコードとノート。

- AtCoder: [Yorihide_Saito](https://atcoder.jp/users/Yorihide_Saito)
- 言語: C++20

## 構成

```
.
├── 30_training/         # 演習カリキュラム
├── src/
│   ├── abcXXX/          # コンテスト本番
│   ├── knowledge/       # テンプレ
│   ├── training/        # 演習
│   └── practice/        # 鉄則本・過去問
└── make_abc.sh
```

## src/knowledge

| ファイル | 内容 |
|---|---|
| union_find.cpp | UnionFind |
| fenwick_tree.cpp | BIT(点更新・区間和) |
| dijkstra.cpp | ダイクストラ |
| grid_bfs.cpp | グリッドBFS |
| binary_search_on_answer.cpp | 答えで二分探索 |
| ncr_mod.cpp | modpow / nCr |
| imos_2d.cpp | 二次元いもす |
| bitdp_tsp.cpp | bitDP |
| sieve_of_eratosthenes.cpp | エラトステネスの篩 |

## ツール

```bash
./make_abc.sh 466   # abc466 のファイル一式を生成
```
