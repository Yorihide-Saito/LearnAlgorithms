#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node {
    map<int, int> to;
    vector<int> ids;
};

int main() {
    int N;
    cin >> N;

    vector<Node> trie(1);
    vector<int> pos(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        int p = pos[x];
        auto it = trie[p].to.find(y);
        if (it == trie[p].to.end()) {
            int v = trie.size();
            trie.push_back(Node{});
            trie[p].to[y] = v;
            pos[i] = v;
        } else {
            pos[i] = it->second;
        }
        trie[pos[i]].ids.push_back(i);
    }

    vector<int> ans;
    auto dfs = [&](auto&& self, int x) -> void {
        for (int id : trie[x].ids) ans.push_back(id);
        for (auto [label, nxt] : trie[x].to) self(self, nxt);
    };
    dfs(dfs, 0);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i + 1 == N? '\n' : ' ');
    }
    return 0;
}