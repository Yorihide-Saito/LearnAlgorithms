#include<iostream>
#include<vector>
#include<numeric>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

const ll INF = (1LL<<60);

struct Rect {
    ll lx, rx, ly, ry;
};

void dfs(int u, const vector<vector<int>>& g, vector<bool>& used, const vector<Rect>& rs, ll& area) {
    used[u] = true;
    const Rect &r = rs[u];
    area += (r.ry - r.ly + 1) * (r.rx - r.lx + 1);
    for (int v : g[u]) {
        if (!used[v]) dfs(v, g, used, rs, area);
    }
}

int main() {
    int N;
    ll X, Y;
    cin >> N >> X >> Y;

    vector<Rect> rects;
    rects.push_back({0, X - 1, 0, Y - 1});

    for (int i = 0; i < N; i++) {
        char C;
        ll A, B;
        cin >> C >> A >> B;

        vector<Rect> nxt;
        for (auto r : rects) {
            if (C == 'X') {
                if (r.lx < A) {
                    ll L = r.lx;
                    ll R = min(r.rx, A - 1);
                    if (L <= R) nxt.push_back({L, R, r.ly - B, r.ry - B});
                }
                if (r.rx >= A) {
                    ll L = max(r.lx, A);
                    ll R = r.rx;
                    if (L <= R) nxt.push_back({L, R, r.ly + B, r.ry + B});
                }
            } else {
                if (r.ly < A) {
                    ll L = r.ly;
                    ll R = min(r.ry, A - 1);
                    if (L <= R) nxt.push_back({r.lx - B, r.rx - B, L, R});
                }
                if (r.ry >= A) {
                    ll L = max(r.ly, A);
                    ll R = r.ry;
                    if (L <= R) nxt.push_back({r.lx + B, r.rx + B, L, R});
                }
            }
        }
        swap(rects, nxt);
    }

    int m = (int)rects.size();
    vector<vector<int>> g(m);

    // O(m^2) になる。
    for (int i = 0; i < m; i++) {
        Rect s = rects[i];
        for (int j = i + 1; j < m; j++) {
            Rect t = rects[j];

            bool xtouch = !(s.rx + 1 <= t.lx || t.rx + 1 <= s.lx);
            bool ytouch = !(s.ry + 1 <= t.ly || t.ry + 1 <= s.ly);
            bool istouch = false;

            // 左右で接する
            if ((s.rx + 1 == t.lx || t.rx + 1 == s.lx) && ytouch) {
                istouch = true;
            }
            // 上下で接する
            if ((s.ry + 1 == t.ly || t.ry + 1 == s.ly) && xtouch) {
                istouch = true;
            }

            if (istouch) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    vector<bool> used(m, false);
    vector<ll> comp_sizes;
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            ll area = 0;
            dfs(i, g, used, rects, area);
            comp_sizes.push_back(area);
        }
    }

    sort(comp_sizes.begin(), comp_sizes.end());
    cout << comp_sizes.size() << endl;
    for (ll v : comp_sizes) cout << v << " ";
    cout << endl;
    return 0;
}