#include<iostream>
#include<cmath>
using namespace std;

// abc071_a
// https://atcoder.jp/contests/abc071/tasks/abc071_a

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    if (abs(B - X) < abs(A - X)) cout << 'B' << endl;
    else cout << 'A' << endl;
    return 0;
}