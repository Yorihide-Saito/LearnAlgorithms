#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int flg = 0;
    for(int i = 0; i < N; i++) {
        if (S[i] != 'o') flg = 1;
        if (flg) cout << S[i];
    }
    cout << endl;
    return 0;
}