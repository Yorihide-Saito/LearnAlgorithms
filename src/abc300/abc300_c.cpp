#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int H, W;
char C[10009][10009];
int ans[101];

int main(){
    if (scanf("%d%d", &H, &W) != 2) return 0;
    for (int i = 0; i < H; i++) {
        scanf("%100s", C[i]);
    }

    for (int i = 1; i < H-1; i++) {
        for (int j = 1; j < W-1; j++) {
            if (C[i][j] == '.') continue;
            int count = 0;
            int rmax = min({ i, j, H - 1 - i, W - 1 - j });

            for (int c = 1; c <= rmax; c++) {
                if (C[i - c][j - c] == '#' && C[i - c][j + c] == '#' && C[i + c][j + c] == '#' && C[i + c][j - c] == '#') {
                    count++;
                } else {
                    break;
                }
            }
            if(count > 0) ans[count] += 1;
        }
    }

    for (int i = 1; i <= min(H, W); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}