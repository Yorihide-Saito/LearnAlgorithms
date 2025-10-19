#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int s, a, b, x; cin >> s >> a >> b >> x;
    int ans = 0;

    int k = x / (a + b);
    int r = x % (a + b);
    ans = k * s * a + s * min(r, a);
    cout << ans << endl;
    return 0;
}