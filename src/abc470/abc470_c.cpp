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

    vector<int> A(N + 1, 0);
    set<int> enabled;

    int ans = 0;
    while(Q--) {
        int Q1;
        cin >> Q1;
        if (Q1 == 1) {
            int x;
            cin >> x;

            int old = A[x];
            A[x] += 1;
            int now = A[x];

            ans ^= old ^ now;

            enabled.insert(x);
        }
        if (Q1 == 2) {
            for (auto it = enabled.begin(); it != enabled.end(); )  {
                int x = *it;

                ans ^= A[x] ^ (A[x] - 1);
                A[x]--;
                if (A[x] == 0) {
                    it = enabled.erase(it);
                }
                else {
                    it++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
