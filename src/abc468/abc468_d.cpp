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

    string S;
    cin >> S;

    int siz = S.size();
    long long ans = 0;
    for (int i = 0; i < siz; i++) {
        int left = i, right = i;
        int count = 0;
        while(left >= 0 && right < siz) {

            if(S[left] != S[right]) count++;
            if (count <= 1) {
                ans++;
                dbg(left, right);
            }
            else {
                break;
            }

            left--;
            right++;
        }
    }

    for (int i = 0; i + 1 < siz; i++) {
        int left = i, right = i + 1;
        int count = 0;
        while(left >= 0 && right < siz) {

            if (S[left] != S[right]) count++;
            if (count <= 1) {
                ans++;
            }
            else {
                break;
            }
            left--;
            right++;
        }
    }

    cout << ans << endl;
    return 0;
}
