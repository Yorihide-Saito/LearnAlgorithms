#include<iostream>
#include<vector>
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> X(H + 1, vector<int>(W + 1, 0)), Z(H + 1, vector<int>(W + 1, 0));

    // 横の累積和の取得
    for(int i = 1; i <= H; i++) {
        int xIN = 0;
        for (int j = 1; j <= W; j++) {
            cin >> xIN;
            X[i][j] = X[i-1][j] + xIN;
        }
    }

    // 縦の累積輪の取得
    for(int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            Z[i][j] = X[i][j] + Z[i][j-1];
        }
    }

    int Q; cin >> Q;
    vector<int> LEFT_P(2, 0), RIGHT_P(2, 0);
    for(int i = 0; i < Q; i++) {
        cin >> LEFT_P[0] >> LEFT_P[1] >> RIGHT_P[0] >> RIGHT_P[1];
        cout << Z[RIGHT_P[0]][RIGHT_P[1]] + Z[LEFT_P[0] - 1][LEFT_P[1] - 1] - Z[LEFT_P[0] - 1][RIGHT_P[1]] - Z[RIGHT_P[0]][LEFT_P[1] - 1] << endl;
    }

    return 0;
}