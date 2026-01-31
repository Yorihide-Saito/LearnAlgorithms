#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

const int INF = 100000000;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for (auto &a: A) cin >> a;

        vector<int> minL = vector<int>(N, INF);
        minL[0] = A[0];
        for (int i = 1; i < N; i++) {
            minL[i] = min(A[i], minL[i - 1] + 1);
        }

        vector<int> minR = vector<int>(N, INF);
        minR[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            minR[i] = min(A[i], minR[i + 1] + 1);
        }

        ll ans = 0;
        for (int i = 0; i < N; i++) {
            int row = min(minL[i], minR[i]);
            ans += (ll)A[i] - (ll)row;
        }

        cout << ans << endl;
    }
    return 0;
}