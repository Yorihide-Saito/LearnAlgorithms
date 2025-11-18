#include<iostream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    vector<ll> cnt(26, 0);
    for (char c : S) {
        cnt[c - 'a']++;
    }

    bool has_dup = false;
    ll total = 1LL * S.size() * (S.size() - 1) / 2; // nC2 の式
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 2) {
            total -= cnt[i] * (cnt[i] - 1) / 2;
            has_dup = true;
        }
    }

    if (has_dup) total++;
    cout << total << endl;
    return 0;
}