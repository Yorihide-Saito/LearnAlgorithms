#include<iostream>
#include<vector>
using namespace std;

int N, X;
vector<int> A;

int search(int x) {
    int L = 1, R = N; // Lは左の先端、Rは右の先端
    while(L <= R) {
        int M = (L + R) / 2;
        if (x < A[M]) R = M - 1; // M を含める必要がないから -1
        if (x == A[M]) return M;
        if (x > A[M]) L = M + 1; // M を含める必要がないから +1
    }
    return -1;
}

int main(){
    cin >> N >> X;
    A.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];

    // もし A がそうとされていない場合はソートを行う
    sort(A.begin(), A.end());
    int Answer = search(X);
    cout << Answer << "\n";
    return 0;
}