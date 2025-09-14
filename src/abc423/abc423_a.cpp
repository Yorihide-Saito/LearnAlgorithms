#include<iostream>
using namespace std;

int main() {
    long long X;
    int C;
    cin >> X >> C;
    long long count = 0;
    long long counter1000 = X / 1000;
    for (int i = 0; i < counter1000; i++) {
        if (X >= 1000 + C) {
            X = X - (1000 + C);
            count++;
        } else {
            break;
        }
    }
    cout << count * 1000 << endl;
    return 0;
}