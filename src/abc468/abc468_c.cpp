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
    vector<int> P(N), Q(N);
    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;

    vector<int> v(N, 0);
    for (int i = 0; i < N; i++) {
        v[i] = i + 1;
    }
    int pos = 0;
    int start = 0, end = 0;

    do {
        pos++;
        if(v == P) start = pos;
        if(v == Q) end = pos;
    } while(next_permutation(v.begin(), v.end()));

    cout << max(0, end - start - 1) << endl;
    return 0;
}
