#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    int a = 0, b = 0, c = 0;
    int ans = 0;

    while(c < S.size()) {
        while(a < S.size() && S[a] != 'A') a++;
        b = max(b, a + 1);
        while(b < S.size() && S[b] != 'B') b++;
        c = max(c, b + 1);
        while(c < S.size() && S[c] != 'C') c++;
        if (a < b && b < c && c < S.size()) ans += 1;
        a++; b++; c++;
    }

    cout << ans << "\n";
    return 0;
}