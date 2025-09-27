#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool is_palindrome(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() {
    string S; cin >> S;
    int n = S.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string t = "";
            for (int k = i; k < j; k++) t+= S[k];
            if (is_palindrome(t)) {
                ans = max(ans, j - i);
            }
        }
    }
    cout << ans << endl;
}