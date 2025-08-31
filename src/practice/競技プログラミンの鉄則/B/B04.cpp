#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;

    // もう少しいい感じに修正できるみたい。
    // 具体的には、char で値を受取り、c が 1 の場合は 1、0 の場合は 0 になる。
    // 最上位ビットから足していきそれを２倍にしていく。
    // for (char c : bin) {
    //     ans = (ans << 1) | (c - '0');
    // }
    for(int i = 8; i > 0; i--) {
        int digit = (N / (int)pow(10, i)) % 10;
        ans = ans * 2 + digit;
    }

    cout << ans << endl;
    return 0;
}