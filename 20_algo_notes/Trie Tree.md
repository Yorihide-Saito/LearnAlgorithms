tags: #algorithm #data-structure #string

---

## 概要

Trie木（トライ木）。**文字列の集合を効率的に管理**するデータ構造。文字列の検索・挿入・接頭辞判定を高速に行える。

## 計算量

- 挿入: `O(L)` (L: 文字列の長さ)
- 検索: `O(L)`
- 接頭辞判定: `O(L)`

## 実装コード

### 基本的なTrie

```cpp
struct Trie {
    map<char, Trie*> child;
    bool is_end;  // この位置で終わる文字列があるか

    Trie() : is_end(false) {}

    // 文字列を挿入
    void insert(const string &s) {
        Trie* cur = this;
        for (char c : s) {
            if (!cur->child.count(c)) {
                cur->child[c] = new Trie();
            }
            cur = cur->child[c];
        }
        cur->is_end = true;
    }

    // 文字列が存在するか検索
    bool search(const string &s) {
        Trie* cur = this;
        for (char c : s) {
            if (!cur->child.count(c)) return false;
            cur = cur->child[c];
        }
        return cur->is_end;
    }

    // 接頭辞が存在するか
    bool starts_with(const string &prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            if (!cur->child.count(c)) return false;
            cur = cur->child[c];
        }
        return true;
    }
};
```

### 配列ベースのTrie（高速版）

```cpp
struct Trie {
    vector<map<int, int>> nodes;  // nodes[v][c] = vからcで遷移した先
    vector<bool> is_end;

    Trie() {
        nodes.push_back(map<int, int>());
        is_end.push_back(false);
    }

    void insert(const vector<int> &s) {
        int cur = 0;
        for (int c : s) {
            if (!nodes[cur].count(c)) {
                nodes[cur][c] = nodes.size();
                nodes.push_back(map<int, int>());
                is_end.push_back(false);
            }
            cur = nodes[cur][c];
        }
        is_end[cur] = true;
    }

    bool search(const vector<int> &s) {
        int cur = 0;
        for (int c : s) {
            if (!nodes[cur].count(c)) return false;
            cur = nodes[cur][c];
        }
        return is_end[cur];
    }
};
```

### 競プロ向けシンプル実装（ABC437E型）

```cpp
struct Node {
    map<int, int> to;    // ラベル -> 次のノードID
    vector<int> ids;     // このノードに到達した要素のID
};

int main() {
    int N;
    cin >> N;

    vector<Node> trie(1);
    vector<int> pos(N + 1, 0);  // pos[i] = i番目の要素が到達するノード

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        int p = pos[x];  // 親ノード
        auto it = trie[p].to.find(y);

        if (it == trie[p].to.end()) {
            // 新しいノードを作成
            int v = trie.size();
            trie.push_back(Node{});
            trie[p].to[y] = v;
            pos[i] = v;
        } else {
            // 既存のノードを使う
            pos[i] = it->second;
        }

        trie[pos[i]].ids.push_back(i);
    }

    // DFSで辞書順に出力
    vector<int> ans;
    auto dfs = [&](auto&& self, int x) -> void {
        for (int id : trie[x].ids) ans.push_back(id);
        for (auto [label, nxt] : trie[x].to) self(self, nxt);
    };
    dfs(dfs, 0);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i + 1 == N ? '\n' : ' ');
    }

    return 0;
}
```

**ポイント**:
- `map<int, int> to` でラベルから次ノードへの遷移を管理
- `vector<int> ids` で各ノードに到達した要素を記録
- mapは自動的にソートされるため、辞書順の探索が簡単
- 再帰ラムダ `auto&& self` でDFSを実装

## 使用例

- 文字列検索（辞書・オートコンプリート）
- 接頭辞マッチング
- XOR最大化問題（2進数でTrie）
- 文字列の辞書順ソート

## 応用: XOR最大化

```cpp
// 整数のビット列をTrieで管理してXOR最大化
struct BinaryTrie {
    vector<array<int, 2>> nodes;  // nodes[v][0/1] = 次のノード
    int B;  // ビット数

    BinaryTrie(int b) : B(b) {
        nodes.push_back({-1, -1});
    }

    void insert(int x) {
        int cur = 0;
        for (int i = B - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (nodes[cur][bit] == -1) {
                nodes[cur][bit] = nodes.size();
                nodes.push_back({-1, -1});
            }
            cur = nodes[cur][bit];
        }
    }

    // xとXORして最大になる値を求める
    int max_xor(int x) {
        int cur = 0;
        int res = 0;
        for (int i = B - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            // 反対のビットがあれば選ぶ
            if (nodes[cur][1 - bit] != -1) {
                res |= (1 << i);
                cur = nodes[cur][1 - bit];
            } else {
                cur = nodes[cur][bit];
            }
        }
        return res;
    }
};
```

## 注意点

- メモリ使用量が多い（文字種×文字列数）
- 小文字アルファベットなら `vector<array<int, 26>>` が速い
- 削除操作は実装が複雑になる
- 数値列にも適用可能（ラベルを整数にする）
