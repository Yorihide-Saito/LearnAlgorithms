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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> p(N + 1), inv(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        inv[p[i]] = i;
    }

    while(Q--) {
        int Q1;
        cin >> Q1;

        if (Q1 == 1) {
            int X, Y;
            cin >> X >> Y;

            int a = p[X];
            int b = p[Y];

            swap(p[X], p[Y]);
            swap(inv[a], inv[b]);
        }
        else {
            swap(p, inv);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << p[i];
        if (i == N) {
            cout << endl;
        }
        else {
            cout << ' ';
        }
    }

    return 0;
}
