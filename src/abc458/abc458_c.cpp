#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    long long ans = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            ans++;
            ans += min((long long)i, (long long)S.size() - i - 1);
        }
    }
    cout << ans << endl;
    return 0;
}