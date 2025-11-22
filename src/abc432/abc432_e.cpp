#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

struct SegTree{
    int n;
    vector<ll> seg;

    SegTree(int N) {
        n = 1;
        while(n < N) n <<= 1;
        seg.assign(2 * n, 0LL);
    }

    void set_value(int pos, ll value) {
        int k = pos + n;
        seg[k] = value;
        while(k >>= 1) {
            seg[k] = seg[2 * k] + seg[2 * k + 1];
        }
    }

    ll query(int l, int r) {
        ll left_res = 0;
        ll right_res = 0;

        l += n;
        r += n;

        while (l < r) {
            if (l & 1) {
                left_res += seg[l++];
            }
            if (r & 1) {
                right_res += seg[--r];
            }

            l >>= 1;
            r >>= 1;
        }
        return left_res + right_res;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    const int MAXA = 500000;
    const int SZ = MAXA + 2;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    SegTree seg_cnt(SZ), seg_sum(SZ);

    for (int i = 1; i <= N; i++) {
        int v = A[i];
        seg_cnt.set_value(v, 1);
        seg_sum.set_value(v, v);
    }

    while(Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;

            int oldv = A[x];
            seg_cnt.set_value(oldv, -1);
            seg_sum.set_value(oldv, -oldv);

            A[x] = y;
            seg_cnt.set_value(y, 1);
            seg_sum.set_value(y, y);
        }
        else {
            ll l, r;
            cin >> l >> r;

            if (l >= r ) {
                cout << l * (ll)N << endl;
                continue;
            }

            ll cnt_less = seg_cnt.query(0, (int)l);
            ll sum_lt_l = seg_sum.query(0, (int)l);

            ll cnt_le_r = seg_cnt.query(0, (int)r + 1);
            ll sum_le_r = seg_sum.query(0, (int)r + 1);

            ll sum_between = sum_le_r - sum_lt_l;
            ll cnt_greater = (ll)N - cnt_le_r;

            ll ans = sum_between + 1 * cnt_less + r * cnt_greater;
            cout << ans << endl;
        }
    }

    return 0;
}