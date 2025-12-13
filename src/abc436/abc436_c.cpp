#include<iostream>
#include<unordered_set>
#include<utility>
using namespace std;
using ll = long long;

struct pHash {
    size_t operator()(const pair<ll, ll> &p) const {
        return p.first << 32 ^ (p.second);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pair<ll, ll>, pHash> grid;
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ll R, C;
        cin >> R >> C;
        R--; C--;

        if (grid.find({R, C}) != grid.end()) continue;

        if (R - 1 >= 0 && grid.find({R - 1, C}) != grid.end()) continue;
        if (C - 1 >= 0 && grid.find({R, C - 1}) != grid.end()) continue;
        if (R - 1 >= 0 && C - 1 >= 0 && grid.find({R - 1, C - 1}) != grid.end()) continue;

        if (R + 1 < N-1 && grid.find({R + 1, C}) != grid.end()) continue;
        if (C + 1 < N-1 && grid.find({R, C + 1}) != grid.end()) continue;
        if (R + 1 < N-1 && C + 1 < N-1 && grid.find({R + 1, C + 1}) != grid.end()) continue;

        if (R - 1 >= 0 && C + 1 < N-1 && grid.find({R - 1, C + 1}) != grid.end()) continue;
        if (R + 1 < N-1 && C - 1 >= 0 && grid.find({R + 1, C - 1}) != grid.end()) continue;

        grid.emplace(R, C);
        ans++;
    }
    cout << ans << endl;
    return 0;
}