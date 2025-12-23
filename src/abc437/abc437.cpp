#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
#include<algorithm>
using namespace std;
using ll = long long;

struct Node {
    vector<pair<int, int>> child;
    vector<int> ids;
};

int main() {
    int N;
    cin >> N;

    vector<int> x(N + 1), y(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<Node> trie(1);
    vector<int> pos(N + 1, 0);

    unordered_map<uint64_t, int> go;

    auto next_node = [&](int p, int label) -> int {
        uint64_t key = (uint64_t)(uint32_t) p << 32 | (uint32_t) label;
        auto it = go.find(key);
        if (it != go.end()) return it->second;

        int v = (int)trie.size();
        trie.push_back(Node{});
        go.emplace(key, v);
        trie[p].child.push_back({label, v});
        return v;
    };

    for (int i = 1; i <= N; i++) {
        int p = pos[x[i]];
        int v = next_node(p, y[i]);
        pos[i] = v;
        trie[v].ids.push_back(i);
    }

    for (auto &nd : trie) {
        sort(nd.child.begin(), nd.child.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });
    }

    vector<int> ans;
    ans.reserve(N);

    vector<int> st = {0};
    vector<int> it(trie.size(), 0);

    while(!st.empty()) {
        int v = st.back();
        if (it[v] == 0) {
            for (int id : trie[v].ids) ans.push_back(id);
        }

        if (it[v] < (int)trie[v].child.size()) {
            int to = trie[v].child[it[v]++].second;
            st.push_back(to);
        } else {
            st.pop_back();
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i + 1 == N ? '\n' : ' ');
    }
    return 0;
}