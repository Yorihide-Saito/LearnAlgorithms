#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<deque>
#include<algorithm>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto &a : A) cin >> a;

    vector<ll> a = A;
    for (auto tmp : A) a.push_back(tmp - 1);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    auto id = [&](ll v) {
        return lower_bound(a.begin(), a.end(), v) - a.begin();
    };

    vector<ll> dp(a.size(), 0);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll id_a = id(A[i]);
        ll id_b = id(A[i] - 1);

        dp[id_a] = max(dp[id_a], dp[id_b] + 1);
        ans = max(ans, dp[id_a]);
    }

    cout << ans << endl;
    return 0;
}