#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> s(2, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int c, p; cin >> c >> p;
        c--;

        s[0][i] = s[0][i - 1];
        s[1][i] = s[1][i - 1];

        s[c][i] +=  p;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << s[0][r] - s[0][l-1] << ' ' << s[1][r] - s[1][l-1] << endl;
    }
    return 0;
}