#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    int size_A = A.size();

    map<ll, ll> m;
    for (int i = 0; i < size_A; i++) {
        m[A[i]] += 1;
    }

    ll ans = 0;
    for (auto [k, v] : m) {
        ll y = 0;
        for (ll i = 0; i < k; i++) y = y * 10 + v;
        ans += y;
    }

    cout << ans << endl;
    return 0;
}