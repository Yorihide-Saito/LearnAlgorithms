#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    char X;
    cin >> X;
    int X_num = X - 'A';
    vector<bool> cher(N, 0);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S[X_num] == 'x') continue;
        else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}