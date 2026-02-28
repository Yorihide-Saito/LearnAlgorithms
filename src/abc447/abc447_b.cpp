#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    map<char, int> m;
    int max_num = 0;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        m[c] += 1;
        max_num = max(m[c], max_num);
    }

    for (int i = 0; i < S.size(); i++) {
        if (m[S[i]] == max_num) continue;
        cout << S[i];
    }

    cout << '\n';
    return 0;
}