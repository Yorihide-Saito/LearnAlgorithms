#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<utility>
using namespace std;

long long INF = 4e18;

int main () {
    int n; cin >> n;
    vector<long long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    a.push_back(INF);
    sort(a.begin(), a.end());

    int q; cin >> q;
    vector<pair<long long, int>> b;
    for(int i = 0; i < q; i++) {
        long long b_in;
        cin >> b_in;
        b.push_back({b_in, i});
    }

    sort(b.begin(), b.end(), [](auto &l, auto &r) { return l.first < r.first; });

    int point = 0;
    vector<long long> ans(b.size());
    for (auto [key, value] : b) {
        while(a.size() > point + 1 && key > a[point + 1]) point++;
        ans[value] = min(llabs(key - a[point]), llabs(key - a[point + 1]));
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;;
    }

    return 0;
}