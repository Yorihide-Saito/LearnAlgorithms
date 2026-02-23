#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    reverse(A.begin(), A.end());
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        ans[i] = max(ans[(N - A[i])], A[i]);
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}