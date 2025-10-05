#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;

    vector<long long> pc(n + 1, 0);
    for (int i = 1; i <= n; i++) pc[i] = 1;

    int o = 1;

    while (q--) {
        int x, y; cin >> x >> y;

        long long moved = 0;
        int upto = (x < n ? x : n);
        for (int i = o; i <= upto; i++) {
            if (i == y) continue;
            if (pc[i] == 0) continue;
            moved += pc[i];
            pc[y] += pc[i];
            pc[i] = 0;
        }
        o = x;
        cout << moved << '\n';
    }
    return 0;
}