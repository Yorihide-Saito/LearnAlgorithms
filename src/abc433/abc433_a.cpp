#include<iostream>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (X < Y) {
        cout << "No" << endl;
        return 0;
    }

    while (X < 100 * Z) {
        if (X == Y * Z) {
            cout << "Yes" << endl;
            return 0;
        }
        X++;
        Y++;
    }
    cout << "No" << endl;
    return 0;
}