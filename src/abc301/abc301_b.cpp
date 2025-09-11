#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int A[N+1];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cout << A[i] << " ";
        if (A[i]+1 > A[i+1]) {
            for (int j = 1; j < A[i] - A[i+1]; j++) cout << A[i] - j << " ";
        } else if (A[i]+1 < A[i+1]) {
            for (int j = 1; j < A[i+1] - A[i]; j++) cout << A[i] + j << " ";
        }
    }
    cout << A[N - 1] << endl;
    return 0;
}