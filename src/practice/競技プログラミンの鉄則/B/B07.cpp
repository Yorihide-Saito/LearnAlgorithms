#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T, N, L, R;
    vector<int> B(T, 0);

    cin >> T;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> L >> R;
        B[L] += 1;
        B[R+1] -= 1;
    }

    int ans = 0;
    for (int j = 0; j < T; j++) {
        ans += B[j];
        cout << ans << endl;
    }
    return 0;
}