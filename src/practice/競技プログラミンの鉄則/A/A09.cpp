#include<iostream>
#include<vector>
using namespace std;

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> grid(H + 2, vector<int>(W + 2, 0));

    for(int i = 0; i < N; i++) {
        int A, B, C, D; cin >> A >> B >> C >> D;
        grid[A][B] += 1;
        grid[A][D+1] -= 1;
        grid[C+1][B] -= 1;
        grid[C+1][D+1] += 1;
    }

    for(int i = 1; i < H + 1; i++){
        int row_sum = 0;
        for (int j = 1; j < W + 1; j++){
            row_sum += grid[i][j];
            grid[i][j] = grid[i-1][j] + row_sum;
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}