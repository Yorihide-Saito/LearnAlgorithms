#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int H, W, N; cin >> H >> W >> N;
    vector<vector<int>> grid(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> ans(H);

    while(N--) {
        int B; cin >> B;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == B) ans[i] += 1;
            }
        }
    }

    int max_ans = 0;
    for (auto a : ans) {
        max_ans = max(a, max_ans);
    }

    cout << max_ans << endl;
    return 0;
}