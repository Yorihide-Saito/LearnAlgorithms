#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << '(' << p.first << ',' << p.second << ')';
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << '[';
    for (size_t i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i];
    return os << ']';
}
template <class T> void dbg_out(const T& a) { cerr << a << endl; }
template <class T, class... U>
void dbg_out(const T& a, const U&... b) { cerr << a << ", "; dbg_out(b...); }
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "] = ", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const long long INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T;
    cin >> T;
    while(T--) {
        long long Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
        cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;

        __int128_t a1 = 2 * ((__int128_t)Qx - Px);
        __int128_t b1 = 2 * ((__int128_t)Qy - Py);
        __int128_t c1 = (__int128_t) Qx * Qx + (__int128_t) Qy * Qy - (__int128_t) Px * Px - (__int128_t) Py * Py;

        __int128_t a2 = 2 * ((__int128_t)Rx - Sx);
        __int128_t b2 = 2 * ((__int128_t)Ry - Sy);
        __int128_t c2 = (__int128_t) Rx * Rx + (__int128_t) Ry * Ry - (__int128_t) Sx * Sx - (__int128_t) Sy * Sy;

        __int128_t d = a1 * b2 - a2 * b1;

        if (d != 0) {
            cout << "Yes" << endl;
        }
        else {
            if(!(a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1)) {
                cout << "No" << endl;
                continue;
            }
            cout << "Yes" << endl;
        }
    }

    return 0;
}
