#include<iostream>
#include<string>
using namespace std;

// abc286_b
// https://atcoder.jp/contests/abc286/tasks/abc286_b

int main() {
    int N; cin >> N;
    string S; cin >> S;

    for (int i = 0; i < N; i++) {
        if (i + 1 < N && S[i] == 'n' && S[i + 1] == 'a') {
            cout << "nya";
            i++;
        } else {
            cout << S[i];
        }
    }

    cout << endl;
    return 0;
}