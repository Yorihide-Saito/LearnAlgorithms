#include<bits/stdc++.h>
using namespace std;

int N, X;
string S[10009];
string Y;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    cin >> X >> Y;
    if (S[X-1] == Y) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}