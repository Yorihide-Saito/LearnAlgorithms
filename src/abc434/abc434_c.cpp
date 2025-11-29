#include<iostream>
#include<vector>
#include<utility>
#include<iomanip>
using namespace std;
using ll = long long;

const ll INF = 1e9;

int main() {
    int T;
    cin >> T;

    while(T--) {
        ll N, H;
        cin >> N >> H;

        ll bottom, up; bottom = up = H;
        ll prev_t = 0;
        int flag = 0;
        while(N--) {
            ll t, l ,u;
            cin >> t >> l >> u;

            if (flag) continue;

            ll dt = t - prev_t;
            prev_t = t;

            bottom -= dt;
            up += dt;

            // cout << "bottom: " << bottom << " up: " << up << endl;

            if (up < l || u < bottom) {
                flag = 1;
                continue;
            }

            if (bottom < l) bottom = l;
            if (up > u) up = u;

            if (bottom < 0) bottom = 0;
            if (up > INF + H) up = INF + H;

            // cout << "custom bottom: " << bottom << " up: " << up << endl;
        }
        if (!flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}