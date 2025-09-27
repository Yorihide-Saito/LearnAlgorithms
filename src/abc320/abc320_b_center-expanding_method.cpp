#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int expandLen(const string &s, int L, int R) {
    int n = s.size();
    while(L >= 0 && R < n && s[L] == s[R]) {
        L--; R++;
    }
    return R - L - 1;
}

int main() {
    string S; cin >> S;
    int n = S.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int len1 = expandLen(S, i, i); // 奇数
        int len2 = expandLen(S, i, i+1); // 偶数
        ans = max(ans, max(len1, len2));
    }
    cout << ans << endl;
    return 0;
}