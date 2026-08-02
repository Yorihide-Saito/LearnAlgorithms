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

    int N, M;
    cin >> N >> M;

    vector<int> A(M, 0), B(M, 0);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }

    auto valid = [&](int x, int y) {
        for (int i = 0; i < M; i++) {
            if (A[i] != x && B[i] != x && A[i] != y && B[i] != y) {
                return false;
            }
        }
        return true;
    };

    auto f = [&](int x) {
        int res = 0;
        for (int i = 0; i < M; i++) {
            if(A[i] != x && B[i] != x) {
                if(valid(x, A[i])) res++;
                if(valid(x, B[i])) res++;
                return res;
            }
        }
        return N - 1;
    };

    int ans = f(A[0]) + f(B[0]);
    if(valid(A[0], B[0])) ans--;

    cout << ans << endl;

    return 0;
}
