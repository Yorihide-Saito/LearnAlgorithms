#include<iostream>
using namespace std;

int main() {
    int s, a, b, x; cin >> s >> a >> b >> x;
    int ans = 0;
    while (x - (a + b) >= 0) {
        ans += s * a;
        x -= (a + b);
    }
    if (x >= a) ans += s * a;
    else ans += (s * x);

    cout << ans << endl;;
    return 0;
}