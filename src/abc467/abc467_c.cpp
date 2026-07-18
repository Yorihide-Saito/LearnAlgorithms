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

    long long N, M;
    cin >> N >> M;

    vector<long long> A(N), B(N - 1);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<long long> dp(M, INF);
    // 初期設定、A[0]の時の i の場合の最小操作回数
    for (int i = 0; i < M; i++) {
        dp[i] = (i - A[0] + M) % M;
    }

    // N = 1 以降の最小を加算する
    for (int i = 1; i < N; i++) {
        vector<long long> ndp(M, INF);

        for (int j = 0; j < M; j++) {
            long long prev = (B[i - 1] - j + M) % M;
            long long cost = (j - A[i] + M) % M;

            ndp[j] = dp[prev] + cost;
        }

        dp = move(ndp);
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;

    return 0;
}
