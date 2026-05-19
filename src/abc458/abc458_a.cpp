#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    int N;
    cin >> S >> N;
    for (int i = 0; i < S.size() - 1; i++) {
        if (N - 1 < i && S.size() - N > i) cout << S[i];
    }
    cout << endl;
    return 0;
}