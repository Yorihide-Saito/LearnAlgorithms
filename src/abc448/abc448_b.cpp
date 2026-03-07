#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    for (int i = 0; i < M; i++) cin >> C[i];

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i] - 1;
        if (C[a] > 0) {
            ans += min(B[i], C[a]);
            C[a] -= B[i];
        }
    }

    cout << ans << endl;
    return 0;
}