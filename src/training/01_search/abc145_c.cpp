// [01-1] ABC145C Average Length
// https://atcoder.jp/contests/abc145/tasks/abc145_c
// パターン: 順列全探索
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
    cin >> n;
    vector<double> x(n, 0), y(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    auto dist = [&](int i, int j) -> double {
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        return sqrt(dx * dx + dy * dy);
    };

    double ans = 0;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) v[i] = i;
    do {
        for(int i = 0; i < n-1; i++) {
            ans += dist(v[i], v[i+1]);
        }
    } while(next_permutation(v.begin(), v.end()));
    int factorial = 1;
    for (int i = 2; i <= n; i++) {
        factorial *= i;
    }
    cout << fixed << setprecision(10) << ans / factorial << endl;
    return 0;
}
