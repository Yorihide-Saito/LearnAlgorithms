#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long X, Y, K;
        cin >> X >> Y >> K;

        auto depth = [&] (long long x) {
            long long d = 0;
            while(x > 0) {
                x = x / K;
                d++;
            }
            return d;
        };

        long long dx = depth(X);
        long long dy = depth(Y);

        long long ans = 0;

        while(dx > dy) {
            X /= K;
            dx--;
            ans++;
        }

        while(dy > dx) {
            Y /= K;
            dy--;
            ans++;
        }

        while(X != Y) {
            X /= K;
            Y /= K;
            ans += 2;
        }

        cout << ans << endl;
    }
    return 0;
}