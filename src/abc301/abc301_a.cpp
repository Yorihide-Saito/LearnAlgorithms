#include<iostream>
using namespace std;

int main() {
    int N, T_count = 0, A_count = 0; cin >> N;
    char S[N];
    if (N <= 2) {
        cin >> S[0];
        if (S[0] == 'T') cout << "T" << endl;
        if (S[0] == 'A') cout << "A" << endl;
        return 0;
    }

    int half = N / 2;
    for (int n = 0; n < N; n++) {
        cin >> S[n];
        if (S[n] == 'T') T_count++;
        if (S[n] == 'A') A_count++;
        if (T_count >= half) {
            cout << "T" << endl;
            break;
        }
        if (A_count >= half) {
            cout << "A" << endl;
            break;
        }
    }
    return 0;
}