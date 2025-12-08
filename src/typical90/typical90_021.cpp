#include<iostream>
#include<vector>
#include<stack>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N), revGraph(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        revGraph[B].push_back(A);
    }

    vector<int> restLength(N, -1);
    vector<int> visited(N, 0);
    int timer = 0;

    for (int start = 0; start < N; start++) {
        if (visited[start]) continue;

        stack<pair<int, int>> st;
        st.push({start, 0});
        visited[start] = 1;

        while(!st.empty()) {
            auto &top = st.top();
            int v = top.first;
            int &idx = top.second;

            if (idx < (int)graph[v].size()) {
                int to = graph[v][idx++];
                if (!visited[to]) {
                    visited[to] = 1;
                    st.push({to, 0});
                }
            } else {
                restLength[v] = timer++;
                st.pop();
            }
        }
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
        [&] (int i, int j) {
            return restLength[i] > restLength[j];
        });


    vector<int> visited2(N, 0);
    vector<int> group(N, -1);
    int cnt = 1;

    for (auto start : idx) {
        if (visited2[start]) continue;

        stack<int> s2;
        s2.push(start);
        visited2[start] = 1;
        group[start] = cnt;

        while(!s2.empty()) {
            int current = s2.top();
            s2.pop();

            for (auto u : revGraph[current]) {
                if (!visited2[u]) {
                    visited2[u] = 1;
                    group[u] = cnt;
                    s2.push(u);
                }
            }
        }
        cnt++;
    }

    vector<ll> sz(cnt, 0);
    for (int v = 0; v < N; v++) {
        sz[group[v]]++;
    }

    ll ans = 0;
    for (int i = 0; i < cnt; i++) {
        ans += sz[i] * (sz[i] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}