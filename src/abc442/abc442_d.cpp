#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

struct SegmentTree {
    int n;
    vector<ll> seg;

    SegmentTree(int N) {
        n = 1;
        while(n < N) n <<= 1;
        seg.assign(2 * n, 0LL);
    }

    ll get_value(int pos) {
        int k = pos + n;
        return seg[k];
    }

    void set_value(int pos, ll value) {
        int k = pos + n;
        seg[k] = value;

        while (k >>= 1) {
            seg[k] = seg[2 * k] + seg[2 * k + 1];
        }
    }

    ll query(int l, int r) {
        ll left_res = 0;
        ll right_res = 0;

        l += n;
        r += n;

        while(l < r) {
            if (l & 1) left_res += seg[l++];
            if (r & 1) right_res += seg[--r];

            l >>= 1;
            r >>= 1;
        }

        return left_res + right_res;
    }
};

int main() {
    int N;
    ll Q;
    cin >> N >> Q;

    SegmentTree seg = SegmentTree(N);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg.set_value(i, A);
    }

    while(Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            x--;

            int x_1 = seg.get_value(x);
            int x_2 = seg.get_value(x + 1);

            seg.set_value(x, x_2);
            seg.set_value(x + 1, x_1);

        }
        if (q == 2) {
            int l, r;
            cin >> l >> r;
            l--;

            cout << seg.query(l, r) << endl;
        }
    }
    return 0;
}