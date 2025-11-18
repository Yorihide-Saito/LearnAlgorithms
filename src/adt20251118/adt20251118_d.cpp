#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string T;
    cin >> T;

    vector<int> ans(2, 0);
    int direction = 0; // 0 東、1 南、2 西、3 北
    for (int i = 0; i < N; i++) {
        if (T[i] == 'S') {
            if (direction == 0) ans[0]++;
            if (direction == 1) ans[1]--;
            if (direction == 2) ans[0]--;
            if (direction == 3) ans[1]++;
        }
        else {
            direction = (direction + 1) % 4;
        }
    }
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}