#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    ll diff = 0;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        diff += abs(A[i] - B[i]);
    }

    if (diff <= K && (K- diff) % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}