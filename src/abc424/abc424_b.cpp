#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> A(K, 0), B(K, 0);

    for (int i = 0; i < K; i++) cin >> A[i] >> B[i];

    long long ans = 0;
    for(int i = 1; i <= M; i++) {
        ans += i;
    }

    vector<long long> ANS(N, ans);
    for (int i = 0; i < K; i++) {
        ANS[A[i] - 1] -= B[i];
        if (ANS[A[i] - 1] == 0) cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}