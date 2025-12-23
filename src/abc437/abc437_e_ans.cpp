#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> x(N + 1), y(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
    }

    // Trie構造: 各ノードは (label, 子ノードid) のペアを持つ
    vector<vector<pair<int, int>>> trie(1);
    vector<vector<int>> ids(1);  // 各ノードに到達するid
    vector<int> pos(N + 1, 0);   // pos[i] = i番目の要素が到達するノード

    // (親ノード, ラベル) -> 子ノードid のマップ
    map<pair<int, int>, int> mp;

    for (int i = 1; i <= N; i++) {
        int p = pos[x[i]];
        int v;

        // 既に子ノードが存在するかチェック
        if (mp.count({p, y[i]})) {
            v = mp[{p, y[i]}];
        } else {
            // 新しいノードを作成
            v = trie.size();
            trie.push_back(vector<pair<int, int>>());
            ids.push_back(vector<int>());
            mp[{p, y[i]}] = v;
            trie[p].push_back({y[i], v});
        }

        pos[i] = v;
        ids[v].push_back(i);
    }

    // 各ノードの子をラベルでソート
    for (auto &node : trie) {
        sort(node.begin(), node.end());
    }

    // DFSで辞書順に出力
    vector<int> ans;
    ans.reserve(N);

    auto dfs = [&](auto &dfs, int v) -> void {
        // このノードに到達したidを追加
        for (int id : ids[v]) {
            ans.push_back(id);
        }
        // 子を辞書順に訪問
        for (auto [label, child] : trie[v]) {
            dfs(dfs, child);
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i + 1 == N ? '\n' : ' ');
    }

    return 0;
}
