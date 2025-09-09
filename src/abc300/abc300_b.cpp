#include<iostream>
#include <cstdio>
using namespace std;

int H, W;
char A[39][40], B[39][40];

int main() {
    scanf("%d%d", &H, &W);
    for (int i = 0; i < H; i++) {
        scanf("%39s", A[i]);
    }
    for (int i = 0; i < H; i++) {
        scanf("%39s", B[i]);
    }

    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
            int ok = 1;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[(i - s + H) % H][(j - t + W) % W] != B[i][j]) ok = 0;
                }
            }
            if (ok) {
                printf("Yes\n");
                return 0;
            }
        }
    }

    printf("No\n");
    return 0;
}