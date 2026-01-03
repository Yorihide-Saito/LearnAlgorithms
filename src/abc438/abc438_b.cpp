#include <iostream>
#include <string>
using namespace std;

const int INF = 100000000;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    int ans = INF;

    for (int i = 0; i + M <= N; i++) {
        int tmp = 0;
        for (int k = 0; k < M; k++) {
            int s = S[i + k] - '0';
            int t = T[k] - '0';
            tmp += (s - t + 10) % 10;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}