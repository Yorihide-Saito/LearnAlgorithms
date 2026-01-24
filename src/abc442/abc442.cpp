#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

struct P { ll idx, x, y; };

P sub(P a, P b){ return {a.x-b.x, a.y-b.y}; }
long long cross(P a, P b){ return a.x*b.y - a.y*b.x; }
long long dot(P a, P b){ return a.x*b.x + a.y*b.y; }

bool upper(const P& v){
    return (v.y > 0) || (v.y == 0 && v.x >= 0);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<P> graph;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        graph.push_back({i, x, y});
    }

    sort(graph.begin(), graph.end(), [&](const P& a, const P& b){
        bool au = upper(a), bu = upper(b);
        if (au != bu) return au > bu;
        ll cr = cross(a, b);
        if (cr != 0) return cr > 0;
        return dot(a, a) < dot(b, b);
    });

    vector<int> sum(N * 2);
    for (int i = 0; i < N; i++) {
        sum[graph[i % N].idx] = i;
    }
    for (int i = N; i < N * 2; i++) {
        sum[graph[i % N].idx + N] = i;
    }

    while(Q--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (a < b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        cout << sum[a] - sum[b] + 1 << endl;
    }
    return 0;
}