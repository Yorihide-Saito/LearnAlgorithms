#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        for (int j = 0; j < L; j++) {
            int tmp; cin >> tmp;
            A[i].push_back(tmp);
        }
    }

    int X, Y;
    cin >> X >> Y;
    cout << A[X - 1][Y - 1] << endl;
    return 0;
}