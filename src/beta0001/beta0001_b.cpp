#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<pair<int, int>> P;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (L <= tmp && tmp <= R) P.emplace_back(tmp, i);
    }

    if (P.empty()) {
        cout << -1 << endl;
        return 0;
    }

    sort(P.begin(), P.end());
    int maxP = P.back().first;
    int ans = P.back().second;
    for (int i = P.size() - 1; i >= 0; i--) {
        if (P[i].first == maxP) ans = P[i].second;
    }
    cout << ans + 1 << endl;
    return 0;
}