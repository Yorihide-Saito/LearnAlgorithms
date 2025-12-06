#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    int right = 0;
    int ans = 0;

    right = max(right , 1 + A[1] - 1);

    for (int i = 1; i <= N; i++) {
        if (i <= right) {
            ans++;
            right = max(right, i + A[i] - 1);
        }
    }

    cout << ans << endl;
    return 0;
}