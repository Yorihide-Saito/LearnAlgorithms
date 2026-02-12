#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> D(N + 1);
    D[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
    }

    sort(D.begin(), D.end());
    ll ans = 0;
    for (int i = 0; i <= N - K; i++) {
        ans += D[i];
    }
    cout << ans << endl;
    return 0;
}