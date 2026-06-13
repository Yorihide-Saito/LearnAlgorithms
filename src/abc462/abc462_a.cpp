#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if (0 <= S[i] - '0' && S[i] - '0' <= 9) cout << S[i];
    }
    cout << endl;
    return 0;
}