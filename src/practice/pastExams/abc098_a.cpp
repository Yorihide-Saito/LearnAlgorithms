#include<iostream>
#include<cmath>
using namespace std;

// abc098_a
// https://atcoder.jp/contests/abc098/tasks/abc098_a

int main() {
    int A, B;
    cin >> A >> B;

    cout << max(A + B, max(A - B, A * B)) << endl;
    return 0;
}