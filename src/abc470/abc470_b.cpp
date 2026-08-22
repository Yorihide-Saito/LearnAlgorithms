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
    int maxColor = 0;
    vector<int> ball(N, 0);
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        cin >> tmp;
        ball[tmp]++;
        maxColor = max(ball[tmp], maxColor);
    }

    cout << N - maxColor << endl;

    return 0;
}
