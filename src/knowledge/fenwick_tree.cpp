// ============================================================
// Fenwick Tree / BIT (点更新・区間和)
// 使いどころ: 「更新しながら区間和」「転倒数」「XOR版に改造可」
// 計算量: 更新・取得ともに O(log N)
// 代表問題: ACL Practice B, ABC185F(XOR版), ABC190F(転倒数)
// ============================================================
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<ll> d;
    BIT(int n) : n(n), d(n + 1, 0) {}
    void add(int i, ll x) {          // 0-indexed で i 番目に x を加算
        for (i++; i <= n; i += i & -i) d[i] += x;
    }
    ll sum(int i) {                  // [0, i) の和
        ll s = 0;
        for (; i > 0; i -= i & -i) s += d[i];
        return s;
    }
    ll sum(int l, int r) { return sum(r) - sum(l); } // [l, r)
};

// 転倒数: 左から add(a[i],1) しつつ sum(a[i]+1, n) を足すだけ

int main() {
    BIT bit(5);
    bit.add(1, 3);
    bit.add(3, 5);
    cout << bit.sum(0, 4) << '\n'; // 8
    return 0;
}
