#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int sum = 0;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i <= n; i++) {
        if(sum - a[i] == m) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}