#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N, 0), B(M, 0);
    for (auto &a : A) cin >> a, a *= 2;
    for (auto &b : B) cin >> b;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;
    long long pointA = 0, pointB = 0;
    while(pointB < M) {
        if (pointA >= N) break;
        if (A[pointA] >= B[pointB]) {
            ans++;
            pointA++;
            pointB++;
        }
        else if (A[pointA] < B[pointB]) {
            pointA++;
        }
    }

    cout << ans << endl;
    return 0;
}