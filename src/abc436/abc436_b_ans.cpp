#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N, 0));

    int r, c, k;
    r = 0;
    c = (N - 1) / 2;
    a[r][c] = 1;

    for (int k = 2; k <= (N * N); k++) {
        int ru = (r - 1 + N) % N;
        int rc = (c + 1) % N;

        if (a[ru][rc] == 0) {
            r = ru;
            c = rc;
        } else {
            r = (r + 1) % N;
        }
        a[r][c] = k;
    }

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}