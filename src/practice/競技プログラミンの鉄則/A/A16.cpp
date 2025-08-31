#include<iostream>
#include<algorithm>
using namespace std;

int N;
int A[10009], B[10009];
int dp[10009];

int main(){
    cin >> N;
    for (int i = 1; i <= N - 1; i++) cin >> A[i];
    for (int i = 1; i <= N - 2; i++) cin >> B[i];

    dp[1] = 0;
    dp[2] = A[1];
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + A[i - 1], dp[i - 2] + B[i - 2]);
    }
    cout << dp[N] << "\n";
    return 0;
}