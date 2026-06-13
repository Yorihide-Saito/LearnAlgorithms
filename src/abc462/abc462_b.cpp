#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> B(N + 1);
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int A;
            cin >> A;
            B[A].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << B[i].size() << ' ';
        for (int j = 0; j < B[i].size(); j++) {
            cout << B[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}