#include<iostream>
using namespace std;

int N, A, B;
int C[309];

int main() {
    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0; i < N; i++) scanf("%d", &C[i]);
    int SUM = A + B;

    for (int i = 0; i < N; i++) {
        if (SUM == C[i]) printf("%d\n", i+1);
    }
}