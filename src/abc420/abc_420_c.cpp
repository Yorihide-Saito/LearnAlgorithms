#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, q = 0;
    cin >> n >> q;

    vector<int> a(n, 0);
    for(int i = 0; i<n; i++) cin >> a[i];
    vector<int> b(n, 0);
    for(int i = 0; i<n; i++) cin >> b[i];

    long long S = 0;
    for (int i = 0; i < n; i++) S += min(a[i], b[i]);

    for(int i = 0; i<q; i++) {
        string query;
        int x = 0; long long v;
        cin >> query >> x >> v;
        x--;

        long long before = min(a[x], b[x]);

        if (query == "A") {
            a[x] = v;
        } else if (query == "B") {
            b[x] = v;
        }

        int ans = 0;
        for (int j =0; j<n; j++) {
            ans += min(a[j], b[j]);
        }

        long long after = min(a[x], b[x]);
        S += (after - before);

        cout << S << '\n';
    }
    return 0;
}