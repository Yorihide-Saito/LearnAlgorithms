#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cassert>
using namespace std;
using ll = long long;

// ストリップ分解

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];
    }

    vector<int> ph(N), pw(N);
    iota(ph.begin(), ph.end(), 0);
    iota(pw.begin(), pw.end(), 0);
    sort(ph.begin(), ph.end(), [&](int i, int j) {
        return h[i] > h[j];
    });
    sort(pw.begin(), pw.end(), [&](int i, int j) {
        return w[i] > w[j];
    });

    vector<int> used(N), c(N), r(N);
    int i = 0, j = 0;
    while(i < N) {
        if (h[ph[i]] == H) {
            int u = ph[i];
            used[u] = 1;
            r[u] = 1;
            c[u] = W - w[u] + 1;
            W -= w[u];
        } else {
            assert(w[pw[j]] == W);
            int u = pw[j];
            used[u] = 1;
            r[u] = H - h[u] + 1;
            c[u] = 1;
            H -= h[u];
        }
        while(i < N && used[ph[i]]) i++;
        while(j < N && used[pw[j]]) j++;
    }

    for (int i = 0; i < N; i++) {
        cout << r[i] << ' ' << c[i] << endl;
    }
    return 0;
}