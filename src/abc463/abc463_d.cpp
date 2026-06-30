#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> L(N), R(N);
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return R[i] < R[j];
    });

    auto isOk = [&](long long x) {
        int cnt = 0;
        long long lastR = -1e18;
        for (int id : idx) {
            if (L[id] >= lastR + x) {
                cnt++;
                lastR = R[id];
            }
        }

        return cnt >= K;
    };

    long long l = 0;
    long long r = 1e18;
    while(r - l > 1) {
        long long mid = (l + r) / 2;
        if (isOk(mid)) l = mid;
        else r = mid;
    }
    if (l == 0) cout << "-1" << endl;
    else cout << l << endl;
    return 0;
}