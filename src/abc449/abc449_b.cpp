#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    int sum = H * W;

    while(Q--) {
        int Type;
        cin >> Type;
        if (Type == 1) {
            int R; cin >> R;
            sum -= R * W;
            H -= R;

            cout << R * W << endl;
        } else {
            int C; cin >> C;
            sum -= C * H;
            W -= C;

            cout << C * H << endl;
        }
    }
    return 0;
}