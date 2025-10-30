#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0L;
    for (int i = 0; i < n; i++) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;
    return 0;
}