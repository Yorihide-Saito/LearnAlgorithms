#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int t = 0;
    for (char c : S) if (c == 'o') t ^= 1;

    vector<vector<int>> ls(2);
    int c = t;
    for (int i = N; i >= 1; i--) {
        if (S[i - 1] == 'o') c ^= 1;
        ls[c].push_back(i);
    }
    if (t == 1) {
        for (int i = 0; i < (int)ls[0].size(); i++)  {
            cout << ls[0][i] << ' ';
        }
        for (int i = (int)ls[1].size() - 1; i >= 0; i--) {
            cout << ls[1][i] << ' ';
        }
    }
    else {
        for (int i = 0; i < (int)ls[1].size(); i++) {
            cout << ls[1][i] << ' ';
        }
        for (int i = (int)ls[0].size() - 1; i >= 0; i--) {
            cout << ls[0][i] << ' ';
        }
    }
    cout << endl;
    return 0;
}