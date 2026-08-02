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

    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;

    if (S.size() <= 1 && S[0] == 'x') ans++;
    if (S.size() >= 2 && S[0] == 'x' && S[1] == 'x') ans++;
    if (S.size() >= 2 && S[N - 1] == 'x' && S[N - 2] == 'x') ans++;
    for (int i = 1; i < N - 1; i++) {
        if (S[i - 1] == 'x' && S[i] == 'x' && S[i + 1] == 'x') ans++;
    }

    cout << ans << endl;

    return 0;
}
