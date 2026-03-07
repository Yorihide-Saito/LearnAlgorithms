#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_set>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), idx(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<int> mark(N, -1);

    for (int q = 0; q < Q; q++) {
        int K;
        cin >> K;
        for (int i = 0; i < K; i++) {
            int b;
            cin >> b;
            --b;
            mark[b] = q;
        }

        for (int id : idx) {
            if (mark[id] != q) {
                cout << A[id] << '\n';
                break;
            }
        }
    }
    return 0;
}