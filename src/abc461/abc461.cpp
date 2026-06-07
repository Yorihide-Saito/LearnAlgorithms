#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    vector<long long> count(H * W + 1, 0);
    long long ans = 0;
    for (int i = 0; i < H; i++) {
        vector<int> col(W, 0);

        for (int j = i; j < H; j++) {
            for (int k = 0; k < W; k++) {
                col[k] += S[j][k] - '0';
            }

            vector<int> used;
            count[0] = 1;
            used.push_back(0);

            int sum = 0;
            for (int k = 0; k < W; k++) {
                sum += col[k];
                if (sum >= K) ans += count[sum - K];
                if (count[sum] == 0) used.push_back(sum);
                count[sum]++;
            }

            for (int x : used) {
                count[x] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}