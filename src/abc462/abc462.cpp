#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long A, B, X, Y;
        cin >> A >> B >> X >> Y;
        long long absX = llabs(X);
        long long absY = llabs(Y);

        auto calc = [&](long long x, long long y) {
            long long res = 0;
            long long minSq = min(x, y);
            if (y > x) {
                long long ver = y - x;
                res += ((ver + 2 - 1) / 2) * B;
                res += (ver - ((ver + 2 - 1) / 2)) * A;
            }
            else {
                long long hor = x - y;
                res += ((hor + 2 - 1) / 2) * A;
                res += (hor - ((hor + 2 - 1) / 2)) * B;
            }
            res += minSq * 2 * min(A, B);
            return res;
        };

        long long ans = calc(absX, absY);

        long long x = absX;
        long long y = absY;
        if (absX < absY) {
            x = absY;
            if ((x - absX) % 2 != 0) x++;
        }
        else if (absY < absX) {
            y = absX;
            if ((y - absY) % 2 != 0) y++;
        }

        ans = min (ans, calc(x, y));
        cout << ans << endl;
    }
    return 0;
}