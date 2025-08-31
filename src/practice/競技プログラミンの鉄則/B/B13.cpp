#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;                      // K は金額なので long long
    cin >> N >> K;

    long long A[100009];
    int R[100009];                    // ← サイズを十分に
    for (int i = 1; i <= N; i++) cin >> A[i];

    // ★ 連続区間問題なので sort はしない
    // sort(A + 1, A + N + 1);  ← 削除

    // 累積和 S[i] = A[1] + ... + A[i]
    long long S[100009];
    S[0] = 0;
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

    long long Answer = 0;

    // しゃくとり：R[i] は「i を左端にしたときの最大の右端」
    // 単調性 R[i] >= R[i-1] を使って O(N) にする
    for (int i = 1; i <= N; i++) {
        if (i == 1) R[i] = 0;         // 最初は「空区間」から開始（i-1）
        else        R[i] = R[i - 1];  // 右端は後退しない

        // 区間 [i..R[i]+1] を試して、和が K 以下なら右端を伸ばす
        while (R[i] < N && S[R[i] + 1] - S[i - 1] <= K) {
            R[i]++;
        }

        // i を左端にした「和 ≤ K」の区間の個数は、r = i..R[i] の数
        // 個数 = R[i] - i + 1（R[i] == i-1 なら 0 個）
        Answer += (R[i] - i + 1);
    }

    cout << Answer << "\n";
    return 0;
}