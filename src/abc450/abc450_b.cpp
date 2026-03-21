#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> C(N, vector<int>(N, 0));
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> C[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (C[i][k] > C[i][j] + C[j][k]) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}