#include<iostream>
using namespace std;

int N, S, A[69];
bool dp[69][100009];

int main() {
    cin >> N >> S;
    for(int i = 1; i <= N; i++) cin >> A[i];

    dp[0][0] = true;
    for(int i = 1; i <= S; i++) dp[0][i] = false;

    for (int i = 1; i <= N; i++) {
        for(int j = 0; j <= S; j++) {
            if(j < A[i]) {
                if (dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(j >= A[i]){
                // 今チェックしているカード(A[i])よりも大きい値になるから、
                // j は dp の今チェックしている値で、その値から今チェックしている(A[i])を引いた場所が true の場合は、true で良い。
                // (↑の意味は、今つかするカードから引いた値が、すでに組み合わせとしてありえる値なので引く前も true になる感じ)
                if (dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if(dp[N][S] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}