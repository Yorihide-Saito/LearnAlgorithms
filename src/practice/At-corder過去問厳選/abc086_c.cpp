#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int prev_t = 0, prev_x = 0, prev_y = 0;
    for (int i = 0; i < N; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t - prev_t < x - prev_x + y - prev_y) {
            cout << "No" << endl;
            return 0;
        }
        if (t - prev_t % 2 != (x - prev_x + y - prev_y) % 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}