#include<iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        if (m >= i) cout << "OK" << endl;
        else cout << "Too Many Requests" << endl;
    }
    return 0;
}