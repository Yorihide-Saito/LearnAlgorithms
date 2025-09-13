#include<iostream>
using namespace std;

int main() {
    int A, B, C, X, count = 0;
    cin >> A >> B >> C >> X;
    for (int a = 0; a <= A; a++) {
        for (int b = 0; b <= B; b++) {
            for (int c = 0; c <= C; c++) {
                if ((500 * a) + (100 * b) + (50 * c) == X) count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}