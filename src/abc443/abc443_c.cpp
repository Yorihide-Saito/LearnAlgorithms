#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    // 0回の場合は、Tを返す。
    if (N <= 0) {
        cout << T << endl;
        return 0;
    }

    // slave
    int ans =  0;

    int r = 0, l;
    for (int i = 0; i < N; i++) {
        l = A[i];
        if (l < r) continue;

        ans += (l - r);
        r = l + 100;
    }

    if (r < T) ans += (T - r);
    cout << ans << endl;
    return 0;
}