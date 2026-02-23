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
    sort(ph.begin(), ph.end(), [&](int i, int j) {
        return h[i] > h[j];
    });
    iota(pw.begin(), pw.end(), 0);
    sort(pw.begin(), pw.end(), [&](int i, int j) {
        return w[i] > w[j];
    });

    vector<int> vis(N), x(N), y(N);
    int i = 0, j = 0;
    while(i < N) {
        if (h[ph[i]] == H) {
            int u = ph[i];
            vis[u] = 1;
            x[u] = 1;
            y[u] = W - w[u] + 1;
            W -= w[u];
        } else {
            assert(w[pw[j]] == W);
            int u = pw[j];
            vis[u] = 1;
            x[u] = H - h[u] + 1;
            y[u] = 1;
            H -= h[u];
        }
        while(i < N && vis[ph[i]]) {
            i++;
        }
        while(j < N && vis[pw[j]]) {
            j++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << x[i] << ' ' << y[i] << endl;
    }

    return 0;
}