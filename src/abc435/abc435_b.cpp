#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0), sumA(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sumA[0] = 0;
    for (int i = 1; i <= N; i++) {
        sumA[i] = sumA[i-1] + A[i-1];
    }

    // for (int i = 0; i <= N; i++) cout << sumA[i] << endl;

    int ans = 0;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            ll rangeSumA = sumA[r+1] - sumA[l];
            bool ok = true;
            for (int i = l; i <= r; i++) {
                if (rangeSumA % A[i] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}