#include<iostream>
#include<cmath>
#include<iomanip>
#include<limits>
using namespace std;
using ll = long long;

int main() {
    double T, L, X, Y;
    cin >> T;
    cin >> L >> X >> Y;

    int Q;
    cin >> Q;

    while(Q--) {
        double E;
        cin >> E;

        // 角度
        double theta = 2.0 * M_PI * E / T;

        double y = -(L / 2.0) * sin(theta);
        double z = (L / 2.0) * (1.0 - cos(theta));

        double A = hypot(X, Y - y);
        double B = z;

        double rad = atan2(B, A);
        double deg = rad * 180 / M_PI;

        cout << fixed << setprecision(12) << deg << endl;
    }

    return 0;
}