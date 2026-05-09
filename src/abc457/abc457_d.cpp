#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> A;
    for (int i = 0; i < N; i++) {
        ll tmp; cin >> tmp;
        A.push_back({i + 1, tmp});
    }

    sort(A.begin(), A.end(), [&](auto i, auto j) {
        return i.second < j.second;
    });

    ll low = 0;
    ll high = (A[N - 1].first * K) + A[N - 1].second + 1;

    while(high - low > 1){
        ll mid = low + (high - low) / 2;
        __int128 need = 0;

        for (int i = 0; i < N; i++) {
            if (mid > A[i].second) {
                need += (mid - A[i].second + A[i].first - 1) / A[i].first;
                if (need > K) break;
            }
        }
        if (need <= K) low = mid;
        else high = mid;
    }
    cout << low << endl;
    return 0;
}