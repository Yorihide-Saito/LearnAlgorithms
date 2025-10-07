#include<iostream>
#include<vector>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<int>> graph(H, vector<int>(W, 0));
    vector<int> column_sum(W), row_sum(H);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> graph[i][j];
            // 累積和
            column_sum[j] += graph[i][j];
            row_sum[i] += graph[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << column_sum[j] + row_sum[i] - graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}