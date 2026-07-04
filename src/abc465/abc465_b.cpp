#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int X, Y, L, R, A, B;
    cin >> X >> Y >> L >> R >> A >> B;
    int Xdiff = max(0, min(B, R) - max(L, A));
    cout << Xdiff * X + ((B - A) - Xdiff) * Y << endl;
    return 0;
}