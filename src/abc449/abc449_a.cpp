#include<iostream>
#include<utility>
#include<iomanip>
using namespace std;
using ll = long long;

const double PI = 3.141592653589793;

int main() {
    double D;
    cin >> D;

    cout << fixed << setprecision(16) << double((D / 2) * (D / 2) * PI) << endl;
    return 0;
}