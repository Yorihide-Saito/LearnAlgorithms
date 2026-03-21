#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i] % K;
    }

    sort(B.begin(), B.end());

    int max_gap = 0;
    for (int i = 0; i < N - 1; i++) {
        max_gap = max(max_gap, B[i + 1] - B[i]);
    }
    max_gap = max(max_gap, B[0] + K - B[N - 1]);

    cout << K - max_gap << endl;
    return 0;
}
