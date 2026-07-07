// [02-2] ABC183D Water Heater
// https://atcoder.jp/contests/abc183/tasks/abc183_d
// パターン: いもす法
//
// ---- 3行設計(書いてから実装する) ----
// ① データ構造:
// ② ループ/遷移:
// ③ 答え:

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long w;
    cin >> n >> w;

    vector<long long> s, t, p;
    for (int i = 0; i < n; i++) {
        long long s_in, t_in, p_in;
        cin >> s_in >> t_in >> p_in;
        s.push_back(s_in);
        t.push_back(t_in);
        p.push_back(p_in);
    }

    long long max_time = *max_element(t.begin(), t.end());
    vector<long long> imos(max_time + 1, 0);
    for (int i = 0; i < n; i++) {
        imos[s[i]] += p[i];
        imos[t[i]] -= p[i];
    }

    for (int i = 0; i < max_time; i++) {
        imos[i + 1] += imos[i];
    }

    for (int i = 0; i <= max_time; i++) {
        if (imos[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
