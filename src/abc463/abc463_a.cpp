#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int X, Y;
    cin >> X >> Y;
    if (X % 16 == 0 && Y % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}