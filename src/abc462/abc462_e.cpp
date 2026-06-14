#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long A, B, X, Y;
        cin >> A >> B >> X >> Y;

        long long x = llabs(X);
        long long y = llabs(Y);

        auto calc = [&](long long A, long long B, long long x, long long y) {
            if (A > B) swap(A, B);
            if (x > y) swap(x, y);

            long long ansDec = 2 * A * y;
            long long ansStraight = A * (x + y) + (B - A) * (y - x) / 2;

            return min(ansDec, ansStraight);
        };

        long long ans;
        if ((x + y) % 2 == 0) {
            ans = calc(A, B, x, y);
        }
        else {
            ans = min(calc(A, B, x - 1, y ) + A, calc(A, B, x, y - 1) + B);
        }

        cout << ans << endl;
    }
    return 0;
}