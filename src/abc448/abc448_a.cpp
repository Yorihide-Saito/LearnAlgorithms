#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < X) {
            cout << 1 << endl;
            X = tmp;
        }
        else cout << 0 << endl;
    }
    return 0;
}