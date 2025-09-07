#include<iostream>
#include<algorithm>
using namespace std;

int N;
unsigned long long K;
unsigned long long A[1 << 20];

int main() {
    cin >> N >> K;

    int len = 1;
    A[0] = K;
    for (int i = 0; i < N; i++) {
        int next_len = len * 2;
        for (int j = len - 1; j >= 0; j--) {
            unsigned long long  a = A[j] / 2;
            unsigned long long  b = A[j] - a;
            A[2 * j] = a;
            A[2 * j + 1] = b;
        }
        len = next_len;
    }

    unsigned long long mx = *max_element(A, A + len);
    unsigned long long mn = *min_element(A, A + len);
    cout << (mx - mn) << endl;

    for (int i = 0; i < len; i ++) {
        if (i) cout << " ";
        cout << A[i];
    }

    cout << endl;
    return 0;
}