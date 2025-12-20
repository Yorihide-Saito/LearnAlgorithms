#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<pair<ll, ll>> reindeer;
        for (int i = 0; i < N; i++) {
            ll W, P; cin >> W >> P;
            reindeer.push_back({W, P});
        }

        sort(reindeer.begin(), reindeer.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.first + a.second < b.first + b.second;
        });

        vector<ll> sumW(N + 1, 0), sumP(N + 1, 0);
        for (int i = 0; i < N; i++) {
            sumW[i + 1] = sumW[i] + reindeer[i].first;
        }
        for (int i = N - 1; i >= 0; i--) {
            sumP[i] = sumP[i + 1] + reindeer[i].second;
        }

        int l = 0, r = N;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if (sumW[m] <= sumP[m]) l = m;
            else r = m;
        }

        cout << l << endl;
    }
    return 0;
}