#include<iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int ans = 0;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int z = K - x - y;
            if (z >= 1 && z <= K) ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}