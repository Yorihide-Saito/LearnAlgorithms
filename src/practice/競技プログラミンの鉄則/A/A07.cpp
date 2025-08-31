#include<iostream>
#include<vector>
using namespace std;

int main() {
    int D, N;
    cin >> D;
    cin >> N;
    vector<int> B(D, 0);
    int L, R, ans = 0;

    for(int i = 0; i < N; i++) {
        cin >> L >> R;
        B[L-1] += 1;
        B[R] -= 1;
    }

    for(int j = 0; j < D; j++) {
        ans += B[j];
        cout << ans << endl;
    }

    return 0;
}