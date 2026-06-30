#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    vector<long long> L(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> L[i];
    }

    vector<int> sMax(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        sMax[i] = max(sMax[i + 1], H[i]);
    }

    int Q;
    cin >> Q;
    while(Q--) {
        long long T;
        cin >> T;

        int pos = upper_bound(L.begin(), L.end(), T) - L.begin();
        cout << sMax[pos] << endl;
    }

    return 0;
}