#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++) {
        cin >> C[i];
    }
    int top = H, bottom = 0, left = W, right = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (C[h][w] == '#') {
                top = min(top, h);
                bottom = max(bottom, h);
                left = min(left, w);
                right = max(right, w);
            }
        }
    }

    for (int h = top; h <= bottom; h++) {
        for (int w = left; w <= right; w++) {
            cout << C[h][w];
        }
        cout << endl;
    }
    return 0;
}