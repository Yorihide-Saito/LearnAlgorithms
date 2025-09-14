#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, R; cin >> N >> R;
    vector<int> L(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
    }

    int Left = N + 1, Right = 0;
    for (int i = 1; i <= N; i++) {
        if (L[i] == 0) { Left = i; break; }
    }

    for (int i = N; i > 0; i--) {
        if (L[i] == 0) { Right = i; break; }
    }

    if (Left == N+1) {
        cout << 0 << endl;
        return 0;
    }

    if (R > Right) Right = R;
    else if (R < Left) Left = R + 1;

    int ans = 0;
    for (int i = Left; i <= Right; i++) {
        if (L[i] == 0) { ans++; }
        if (L[i] == 1) { ans+=2; }
    }

    cout << ans << endl;
    return 0;
}