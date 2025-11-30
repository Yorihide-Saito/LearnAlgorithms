#include<iostream>
#include<vector>
#include<utility>
#include<iomanip>
using namespace std;
using ll = long long;

// 2次元 いもす法
int main() {
    int N;
    cin >> N;

    vector<vector<int>> grids(2002, vector<int>(2002, 0));
    vector<vector<int>> id_grids(2002, vector<int>(2002, 0));
    for (int i = 1; i <= N; i++) {
        int U, D, L, R;
        cin >> U >> D >> L >> R;

        grids[U][L] += 1;
        grids[D + 1][L] -= 1;
        grids[U][R + 1] -= 1;
        grids[D + 1][R + 1] += 1;

        id_grids[U][L] += i;
        id_grids[D + 1][L] -= i;
        id_grids[U][R + 1] -= i;
        id_grids[D + 1][R + 1] += i;
    }

    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (!j) continue;
            grids[i][j] += grids[i][j-1];
            id_grids[i][j] += id_grids[i][j-1];
        }
    }

    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (!i) continue;
            grids[i][j] += grids[i-1][j];
            id_grids[i][j] += id_grids[i-1][j];
        }
    }

    vector<ll> bk(N + 1, 0);
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            if (grids[i][j] == 0){
                bk[0]++;
            }
            else if (grids[i][j] == 1) {
                bk[id_grids[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << bk[0] + bk[i] << endl;
    }
    return 0;
}