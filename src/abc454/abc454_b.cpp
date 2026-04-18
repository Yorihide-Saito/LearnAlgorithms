#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> kind(M, 0);

    int isDiff = 1;
    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        F--;
        if (kind[F] == 1) {
            isDiff = 0;
        }
        kind[F] = 1;
    }
    cout << (isDiff ? "Yes" : "No") << endl;;
    for (auto k : kind) {
        if (k == 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}