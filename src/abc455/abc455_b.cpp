#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char> (W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }

    int ans = 0;

    for (int h1 = 0; h1 < H; h1++) {
        for (int h2 = h1; h2 < H; h2++) {
            for (int w1 = 0; w1 < W; w1++) {
                for (int w2 = w1; w2 < W; w2++) {
                    int is_ok = 1;
                    for (int i = h1; i <= h2; i++) {
                        for (int j = w1; j <= w2; j++) {
                            int ni = h1 + h2 - i;
                            int nj = w1 + w2 - j;

                            if (S[i][j] != S[ni][nj]) {
                                is_ok = 0;
                            }
                        }
                    }

                    if (is_ok) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}