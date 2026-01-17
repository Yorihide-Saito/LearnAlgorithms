#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll cost;
};

struct State {
    int v;
    int depth;
    ll cost;
};

int main() {
    ll N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;

    vector<vector<Edge>> graph(N);
    for (ll i = 0; i < M; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        graph[u].push_back({(int)v, c});
    }

    // 可能な Node のステータス
    vector<int> is_ok(N, 0);

    stack<State> st;
    st.push({0, 0, 0});

    while(!st.empty()) {
        auto current = st.top();
        st.pop();

        if (current.cost > T) continue;

        // 規定の辺を通っている場合は、コストが範囲を満たしているかをチェックする。
        if (current.depth == L) {
            if (S <= current.cost && current.cost <= T) {
                is_ok[current.v] = 1;
            }
            continue;
        }

        for (auto e : graph[current.v]) {
            if (current.cost + e.cost > T) continue;
            st.push (
                {
                    e.to,
                    current.depth + 1,
                    current.cost + e.cost
                }
            );
        }
    }

    for (int v = 0; v < N; v++) {
        if (is_ok[v]) {
            cout << v + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
