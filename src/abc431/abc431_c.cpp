#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<long long> H(N, 0), B(M, 0);
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(H.begin(), H.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    int count = 0;
    int j = 0;
    for (int i = 0; i < H.size(); i++) {
        if (H[i] <= B[j]) {
            j++;
            count++;
        }
        else while(H[i] >= B[j] && B.size() < j) j++;

        if (count >= K) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}