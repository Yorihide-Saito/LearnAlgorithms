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

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return B[i] > B[j];
    });

    vector<int> used(N, 0);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int id_a = A[idx[i]] - 1;
        if (!used[id_a]) {
            cout << id_a << endl;
            ans += min(C[id_a], B[idx[i]]);
            used[id_a] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}