#include<iostream>
#include<string>
using namespace std;

int main() {
    string S, T;
    cin >> S;
    cin >> T;
    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < S.size();) {
        if (S[i] != T[i]) {
            if (i + 1 > S.size()) {
                cout << "No" << endl;
                return 0;
            }
            if (!(S[i] == T[i + 1] && S[i + 1] == T[i])) {
                cout << "No" << endl;
                return 0;
            }
            i++;
            count++;
        }
        if (count > 1) {
            cout << "No" << endl;
            return 0;
        }
        i++;
    }
    cout << "Yes" << endl;
    return 0;
}