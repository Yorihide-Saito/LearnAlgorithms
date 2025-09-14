#include<iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int L[N];
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    int i = 0;
    while (L[i] == 0 && i < N) { i++; }
    if (i == N) {
        cout << 0 << endl;
    }

    int j = N - 1;
    while (L[j] == 0 && j > i) { j--; }
    cout << j - i << endl;
    return 0;
}