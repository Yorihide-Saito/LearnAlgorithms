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

    // ① データ構造:
    // ② ループ/遷移:
    // ③ 答え:
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (auto &x : A) cin >> x;

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        if(A[i] < A[i + 1] && A[i + 1] > A[i + 2]) ans++;
    }

    cout << ans << endl;
    return 0;
}
