#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;

    int bit = pow(2, n);
    for (int i = 1; i < bit; i++) {
        if (__builtin_popcount(i) != n / 2) continue;
        int count = 0;
        for (int j = n - 1; j >= 0; j--) {
            if ((i & 1 << j) >= 1) count++;
            else count--;
            if (count < 0) break;
        }
        if(count == 0) ans.push_back(i);
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if ((ans[i] & (1 << j)) > 1) cout << "(";
            else cout << ")";
        }
        cout << endl;
    }
    return 0;
}