#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

const long long INF = (long long)4e18;

int main () {
    int N; cin >> N;
    auto f = [&](long long a, long long b) {
        return (a == INF && b == INF) ? 0 : min(a, b);
    };

    set<long long> s = {-INF, 0, INF};
    long long sum = 0;

    while(N--) {
        long long X; cin >> X;
        auto it = s.lower_bound(X);
        auto ip = prev(it);
        long long q = *it, p = *ip;

        sum += f(X - p, q - X);

        if (p != -INF) {
            long long a = *prev(ip);
            long long old_dp = f(p - a, q - p);
            long long new_dp = f(p - a, X - p);
            sum += new_dp - old_dp;
        }

        if (q != +INF) {
            long long b = *next(it);
            long long old_dq = f(q - p, b- q);
            long long new_dq = f(q - X, b- q);
            sum += new_dq - old_dq;
        }

        s.insert(X);
        cout << sum << endl;
    }
    return 0;
}