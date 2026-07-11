#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> ball(M, -1);
    for (int i = 0; i < N; i++) {
        int C, S;
        cin >> C >> S;
        C--;
        ball[C] = max(S, ball[C]);
    }

    for (auto &x : ball) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
