#include<iostream>
#include<vector>
#include<utility>
#include<iomanip>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> clouds(N);
    for (int i = 0; i < N; i++) {
        int U, D, L, R;
        cin >> U >> D >> L >> R;
        clouds[i] = {U, D, L, R};
    }

    for (int i = 0; i < N; i++) {
        int u, d, l, r;
        u = clouds[i][0];
        d = clouds[i][1];
        l = clouds[i][2];
        r = clouds[i][3];

        ll cloud_size = (d - u) * (r - d);
        vector<vector<int>>
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
                int nu, nd, nl, nr;
                nu = clouds[j][0];
                nd = clouds[j][1];
                nl = clouds[j][2];
                nr = clouds[j][3];

            if (u < nd || nu < d) continue;
            if (r < nl || nr < r) continue;

            if (nu > u) tmp_u = nu;
            if (nd < d) tmp_d = nd;
            if (nr > r) tmp_r = nr;
            if (nl > l) tmp_r = nl;
        }
    }
    return 0;
}