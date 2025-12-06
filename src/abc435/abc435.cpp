#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        graph[Y].push_back(X);
    }

    vector<int> is_black(N, 0);
    vector<int> can_chase_black(N, 0);
    int Q;
    cin >> Q;
    while (Q--) {
        int query, v;
        cin >> query >> v;
        v--;

        if (query == 1) {
            if (is_black[v]) continue;
            is_black[v] = 1;

            queue<int> q;
            q.push(v);
            can_chase_black[v] = 1;
            while(!q.empty()) {
                int x = q.front();q.pop();
                for (int p : graph[x]) {
                    if (!can_chase_black[p]) {
                        can_chase_black[p] = 1;
                        q.push(p);
                    }
                }
            }
        }
        else {
            if (can_chase_black[v]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}