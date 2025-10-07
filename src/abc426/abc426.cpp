#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt[2] = {0, 0}, mx[2] = {0, 0};
        for (int l = 0; l < n; ) {
            int r = l + 1;
            while(r < n && s[r] == s[l]) r++;
            int c = s[l] - '0';
            int len = r - l;
            cnt[c] += len;
            mx[c] = max(mx[c], len);
            l = r;
        }

        int ans = min((cnt[0] - mx[0]) * 2 + cnt[1], (cnt[1] - mx[1]) * 2 + cnt[0]);

        cout << ans << endl;
    }
    return 0;
}