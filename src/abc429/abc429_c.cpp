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

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long a_i = a[i];
        if (a_i > 1) {
            ans += a_i * (a_i - 1) / 2 * (n - a_i);
        }
    }
    cout << ans << endl;
    return 0;
}