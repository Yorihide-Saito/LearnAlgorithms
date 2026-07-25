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

    int M, D;
    cin >> M >> D;
    string S;
    cin >> S;

    vector<int> check(M, 0);
    for (int i = 0; i < M; i++) {
        if (S[i] == 'G') {
            int left = max(0, i - D);
            int right = min(M - 1, i + D);

            for (int j = left; j <= right; j++) {
                check[j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (check[i] != 1) ans++;
    }

    cout << ans << endl;


    return 0;
}
