#include<iostream>
using namespace std;

// abc159_a
// https://atcoder.jp/contests/abc159/tasks/abc159_a
int main() {
    int N, M;
    cin >> N >> M;

    // 下記を求める。
    // 偶数 × 偶数
    // 奇数 × 奇数
    // すなわち、nC2 と mC2 を足したものが答え。
    cout << N * (N - 1) / 2 + M * (M - 1) / 2 << endl;
    return 0;
}