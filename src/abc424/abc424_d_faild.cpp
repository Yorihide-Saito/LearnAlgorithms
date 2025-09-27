#include<iostream>
#include<vector>
using namespace std;

int main () {
    int T; cin >> T;
    char filter[2][2] = {{'#', '#'}, {'#', '#'}};

    for (int i = 0; i < T; i++) {
        int H, W; cin >> H >> W;
        vector<vector<char>> grid(H, vector<char>(W, ' '));
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) cin >> grid[h][w];
        }
        vector<vector<int>> searchGrid(H, vector<int>(W, 0));
        int count = 0;
        for (int j = 0; j < H-1; j++) {
            for (int k = 0; k < W-1; k++) {
                if (grid[j][k] == filter[0][0] &&
                    grid[j+1][k] == filter[1][0] &&
                    grid[j][k+1] == filter[0][1] &&
                    grid[j+1][k+1] == filter[1][1]) {
                        searchGrid[j][k] = 1;
                }
            }
        }

        for (int n = 0; n < H-1; n++) {
            for (int m = 0; m < W-1; m++) {
                if (searchGrid[n][m] && searchGrid[n+1][m] && searchGrid[n][m+1]) {
                    searchGrid[n][m] = searchGrid[n+1][m] = searchGrid[n][m+1] = 0;
                    count++;
                } else if (searchGrid[n+1][m+1] && searchGrid[n+1][m] && searchGrid[n][m+1]) {
                    searchGrid[n+1][m+1] = searchGrid[n+1][m] = searchGrid[n][m+1] = 0;
                    count++;
                } else if (searchGrid[n][m] && searchGrid[n+1][m]) {
                    searchGrid[n][m] = searchGrid[n+1][m] = 0;
                    count++;
                } else if (searchGrid[n][m] && searchGrid[n][m+1]) {
                    searchGrid[n][m] = searchGrid[n][m+1] = 0;
                    count++;
                } else if (searchGrid[n+1][m+1] && searchGrid[n+1][m]) {
                    searchGrid[n+1][m+1] = searchGrid[n+1][m] = 0;
                    count++;
                } else if (searchGrid[n+1][m+1] && searchGrid[n][m+1]) {
                    searchGrid[n+1][m+1] = searchGrid[n][m+1] = 0;
                    count++;
                }
            }
        }
        for (int l = 0; l < H-1; l++) {
            for (int o = 0; o < W-1; o++) {
                if (searchGrid[l][o]) count ++;
            }
        }
        cout << count << endl;
    }
    return 0;
}