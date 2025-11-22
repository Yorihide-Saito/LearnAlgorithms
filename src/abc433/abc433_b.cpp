#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << -1 << endl;
    for (int i = 1 ; i < N; i++) {
        int p = -1;
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i]) p = j + 1;
        }
        cout << p << endl;
    }
    return 0;
}