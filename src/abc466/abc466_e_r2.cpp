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

    // ① データ構造:
    // ② ループ/遷移:
    // ③ 答え:

    int n, k;
    cin >> n >> k;

    long long sum_a = 0;
    vector<vector<long long>> dp(k + 1, vector<long long>(2, -INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        sum_a += a;
        long long diff = b - a;

        vector<vector<long long>> ndp(k + 1, vector<long long>(2, -INF));
        for (int j = 0; j <= k; j++) {
            ndp[j][0] = max(dp[j][0], dp[j][1]);

            if (dp[j][1] != -INF) {
                ndp[j][1] = max(ndp[j][1], dp[j][1] + diff);
            }
            if (j < k && dp[j][0] != -INF) {
                ndp[j + 1][1] = max(ndp[j + 1][1], dp[j][0] + diff);
            }
        }

        dp = move(ndp);
    }

    long long max_diff = 0;
    for (int i = 0; i <= k; i++) {
        max_diff = max(max_diff, dp[i][0]);
        max_diff = max(max_diff, dp[i][1]);
    }
    cout << sum_a + max_diff << endl;

    return 0;
}
