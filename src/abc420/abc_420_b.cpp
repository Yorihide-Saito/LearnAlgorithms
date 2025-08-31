#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> member(m, 0);

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        vector<int> a(m, 0);
        for (int j = 0; j < m; j++) a[j] = s[j] - '0';

        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum == 0 || sum == m) {
            for (int k = 0; k < m; k++) {
                member[k] += 1;
            }
        } else if (sum > m/2) {
            for (int k = 0; k < m; k++) {
                member[k] += a[k];
            }
        } else {
            for (int k = 0; k < m; k++) {
                member[k] += (1 - a[k]);
            }
        }
    }

    int mx = int(max_element(member.begin(), member.end()) - member.begin());

    bool first = true;
    for (int j = 0; j < m; j++) {
        if (member[j] == mx) {
            if (!first) cout << " ";
            cout << j+1;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}
