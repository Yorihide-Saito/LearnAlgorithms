#include<iostream>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    for (int h = 0 ; h < H; h++) {
        if (h == 0 || h == H - 1) {
            for (int w = 0; w < W; w++) {
                cout << '#';
            }
            cout << endl;
        }
        else {
            for (int w = 0; w < W; w++) {
                if (w == 0 || w == W - 1) {
                    cout << '#';
                }
                else {
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
    return 0;
}