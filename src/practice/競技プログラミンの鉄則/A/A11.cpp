#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int half = N / 2;
    while(true) {
        if(X == A[half]) {
            cout << half+1 << "\n";
            break;
        }
        if(X < A[half]) {
            half = half - half / 2;
        } else {
            half = half + half / 2;
        }
    }
    return 0;
}