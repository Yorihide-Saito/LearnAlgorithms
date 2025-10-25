#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        a[num] += 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) {
            ans += a[i] * (a[i] - 1) / 2 * (n - a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}