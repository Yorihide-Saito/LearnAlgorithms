#include<iostream>
using namespace std;

int N, K;
int A[100009], R[100009];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 1; i < N; i++) {
        if (i = 0) R[i] = 1;
        else R[i] = R[i-1];

        while(R[i] < N && A[R[i] + 1] - A[i] <= K){
            R[i] += 1;
        }
    }

    long long Answer = 0;
    for (int i = 1; i < N; i++) Answer += (R[i] - i);
    cout << Answer << "\n";
    return 0;
}
