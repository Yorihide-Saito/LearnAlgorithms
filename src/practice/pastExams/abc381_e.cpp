#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

// abc381_e
// https://atcoder.jp/contests/abc381/tasks/abc381_e

// 部分列の求め方
//
// 部分列？（連続不要）
//  ├─ はい
//  │   ├─ クエリ多い？
//  │   │   ├─ はい → 位置vector + lower_bound
//  │   │   └─ いいえ → ポインタで舐める
//  │   └─ 順序固定？
//  │       ├─ はい → greedy追跡 + 二分探索
//  │       └─ いいえ → DP / 工夫
//  └─ いいえ → RLE / two pointers / segtree

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> idx1, idx2, idxs;
    for (int i = 0; i < N; i++) {
        if(S[i] == '1') idx1.push_back(i);
        else if(S[i] == '2') idx2.push_back(i);
        else idxs.push_back(i);
    }

    auto lb = [&](const vector<int>& v, int x) {
        return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    };

    while(Q--) {
        int L, R;
        cin >> L >> R;
        int l = L - 1, r = R;

        auto ok = [&](int k) -> bool {
            if (k == 0) {
                int j = lb(idxs, l);
                return j < (int)idxs.size() && idxs[j] < r;
            }

            int a = lb(idx1, l);
            if (a + k - 1 >= (int)idx1.size()) return false;
            int j = lb(idxs, idx1[a + k - 1]);
            if (j >= (int)idxs.size()) return false;
            int b = lb(idx2, idxs[j]);
            if (b + k - 1 >= (int)idx2.size()) return false;
            return idx2[b + k - 1] < r;
        };

        int lo = -1, hi = N + 1;
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            (ok(mid) ? lo : hi) = mid;
        }
        cout << (lo < 0 ? 0 : 2 * lo + 1) << endl;
    }
    return 0;
}