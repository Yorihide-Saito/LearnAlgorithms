#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int ans = 0;
    int r = 1;
    for (int l = 1; l <= N; l++) {
        r = max(r, l + 1);
        while(r <= N) {
            cout << "? " << l << " " <<  r << endl;
            string x;
            cin >> x;
            if (x == "No") break;
            if (x == "Yes") {
                r++;
            }
        }

        ans += r - l -1;
    }

    cout << "! " << ans << endl;
    return 0;
}
