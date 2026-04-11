#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int T, X;
    cin >> T >> X;

    vector<int> a(T+1, 0);
    for (int i = 0; i <= T; i++) {
        cin >> a[i];
    }
    // init
    cout << "0 " << a[0] << endl;;
    int bt, ba;
    ba = a[0];
    for (int i = 1; i <= T; i++) {
        if (abs(ba - a[i]) >= X) {
            cout << i << ' ' << a[i] << endl;
            ba = a[i];
        }
    }
    return 0;
}