#include <iostream>
using namespace std;

int H, W;
char s[24][24];

int main() {
    cin >> H >> W;

    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) s[i][j] = '_';
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cin >> s[i][j];
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (s[i][j] != '#') continue;

            int cnt = 0;
            if (s[i-1][j] == '#') cnt++;
            if (s[i+1][j] == '#') cnt++;
            if (s[i][j-1] == '#') cnt++;
            if (s[i][j+1] == '#') cnt++;

            if (cnt == 1 || cnt == 3 || cnt == 0) {
                cout << "No" << "\n";
                return 0;
            }
        }
    }

    cout << "Yes" << "\n";
    return 0;
}