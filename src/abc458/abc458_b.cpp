#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> ans(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans[i][j] = 0;

            if (i-1 >= 0) ans[i][j]++;
            if (i+1 < H) ans[i][j]++;
            if (j-1 >= 0) ans[i][j]++;
            if (j+1 < W) ans[i][j]++;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (j > 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}