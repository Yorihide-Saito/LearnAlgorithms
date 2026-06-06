#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long X1, Y1, R1, X2, Y2, R2;
        cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
        long long X = X1 - X2;
        long long Y = Y1 - Y2;
        long long hypotenuse = X * X + Y * Y;

        long long sum = R1 + R2;
        long long diff = R1 - R2;
        if (sum * sum >= hypotenuse && hypotenuse >= diff * diff) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}