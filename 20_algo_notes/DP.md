tags: #algorithm #dynamic-programming

---

## 概要

動的計画法（Dynamic Programming）。**部分問題の解を保存して再利用**することで、効率的に最適解を求める手法。

## 基本的な考え方

1. 状態を定義する（dp[i] = 〜）
2. 状態間の遷移を考える
3. 初期値とループ順序を決める
4. 答えを取り出す

## 代表的なパターン

### 1. ナップサック問題

```cpp
// 重さ W 以下で価値を最大化
// dp[i][w] = i番目までの品物で重さwの時の最大価値
int N, W;
vector<int> weight(N), value(N);
vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
        // i番目を選ばない
        dp[i + 1][w] = max(dp[i + 1][w], dp[i][w]);

        // i番目を選ぶ
        if (w + weight[i] <= W) {
            dp[i + 1][w + weight[i]] = max(dp[i + 1][w + weight[i]],
                                            dp[i][w] + value[i]);
        }
    }
}

cout << dp[N][W] << endl;
```

### 2. 最長共通部分列（LCS）

```cpp
// 文字列 S と T の LCS の長さ
string S, T;
int n = S.size(), m = T.size();
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (S[i] == T[j]) {
            dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
}

cout << dp[n][m] << endl;
```

### 3. 区間DP

```cpp
// dp[l][r] = 区間 [l, r] の最適値
int N;
vector<int> A(N);
vector<vector<int>> dp(N, vector<int>(N, 0));

// 長さでループ
for (int len = 1; len <= N; len++) {
    for (int l = 0; l + len <= N; l++) {
        int r = l + len - 1;

        if (len == 1) {
            dp[l][r] = 0;  // 初期値
            continue;
        }

        // 区間を分割
        for (int k = l; k < r; k++) {
            dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + cost(l, k, r));
        }
    }
}
```

### 4. bitDP（巡回セールスマン問題など）

```cpp
// dp[S][v] = 集合Sを訪問済みで現在vにいる時の最小コスト
int N;
vector<vector<int>> dist(N, vector<int>(N));
vector<vector<ll>> dp(1 << N, vector<ll>(N, INF));

dp[0][0] = 0;

for (int S = 0; S < (1 << N); S++) {
    for (int v = 0; v < N; v++) {
        if (dp[S][v] == INF) continue;

        for (int nv = 0; nv < N; nv++) {
            if (S >> nv & 1) continue;  // 訪問済み

            int nS = S | (1 << nv);
            dp[nS][nv] = min(dp[nS][nv], dp[S][v] + dist[v][nv]);
        }
    }
}
```

### 5. 桁DP

```cpp
// N以下で条件を満たす数を数える
string N_str;
int K = N_str.size();

// dp[i][tight][条件] = i桁目まで決めた時の個数
// tight = 1: Nと等しい, 0: N未満確定
vector<vector<int>> dp(K + 1, vector<int>(2, 0));
dp[0][1] = 1;

for (int i = 0; i < K; i++) {
    int lim = N_str[i] - '0';

    for (int tight = 0; tight < 2; tight++) {
        if (dp[i][tight] == 0) continue;

        int max_d = tight ? lim : 9;
        for (int d = 0; d <= max_d; d++) {
            int new_tight = tight && (d == lim) ? 1 : 0;
            dp[i + 1][new_tight] += dp[i][tight];
        }
    }
}

cout << dp[K][0] + dp[K][1] << endl;
```

## 計算量

- ナップサック: `O(NW)`
- LCS: `O(NM)`
- 区間DP: `O(N^3)`
- bitDP: `O(2^N × N^2)`

## よくある間違い

- ループ順序を間違える（依存関係を考慮）
- 配列サイズを小さく取りすぎる
- 初期値を間違える（min問題ならINF、max問題なら0など）
- オーバーフローに注意（long longを使う）

## コツ

- まず状態と遷移を紙に書く
- 小さい例で手計算してみる
- メモ化再帰も有効（トップダウンDP）
