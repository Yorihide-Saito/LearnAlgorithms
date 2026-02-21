#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        maxLength = max((int)S[i].size(), maxLength);
    }

    for (int i = 0; i < N; i++) {
        int dotLenght = (maxLength - S[i].size()) / 2;
        for (int j = 0; j < dotLenght; j++) {
            cout << '.';
        }
        cout << S[i];
        for (int j = 0; j < dotLenght; j++) {
            cout << '.';
        }
        cout << endl;
    }

    return 0;
}