#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

long long INF = 4e18;

int main () {
    int n; cin >> n;
    vector<long long> a(n); for(int i = 0; i < n; i++) cin >> a[i];
    a.push_back(INF);

    int q; cin >> q;
    map<long long, int> b;
    for(int i = 0; i < q; i++) {
        long long b_in;
        cin >> b_in;
        b[b_in] = i;
    }

    sort(a.begin(), a.end());

    int point = 0;
    map<long long, int> ans;
    for (auto [key, value] : b) {
        while(a.size() > point + 1 && key > a[point + 1]) point++;
        ans[value] = min(abs(key - a[point]), abs(key - a[point + 1]));
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;;
    }

    return 0;
}