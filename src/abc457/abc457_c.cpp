#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<vector<int>> A(N);
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
        for (int j = 0; j < L[i]; j++) {
            int tmp; cin >> tmp;
            A[i].push_back(tmp);
        }
    }
    for (int i = 0; i < N; i++) {
        ll tmp; cin >> tmp;
        K -= tmp * L[i];
        if (K <= 0) {
            cout << A[i][L[i] + (K % L[i])- 1] << endl;
            return 0;
        }
    }

    return 0;
}