#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int X; cin >> X;
    cout << A[X - 1] << endl;
    return 0;
}