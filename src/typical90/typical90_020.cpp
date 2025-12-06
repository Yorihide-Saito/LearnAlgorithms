#include<iostream>
#include<cmath>
using namespace std;
using ll = long long;

// 累乗（べき乗）はオーバーフローするため、主体で計算する。
bool less_than_pow(ll a, ll c, ll b) {
    ll cur = 1;
    for (ll i = 0; i < b; i++) {
        if (cur > a / c) {
            return true;
        }
        cur *= c;
    }
    return a < cur;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (less_than_pow(a, c, b)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}