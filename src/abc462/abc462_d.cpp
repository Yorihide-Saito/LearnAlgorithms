#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;

    int MAX = 1e6;
    vector<int> diff(MAX + 2, 0);
    for (int i = 0; i < N; i++) {
        int S, T;
        cin >> S >> T;

        if (S <= T - D) {
            diff[S]++;
            diff[T - D + 1]--;
        }
    }

    long long ans = 0;
    long long count = 0;

    for (int i = 0; i < MAX + 2; i++) {
        count += diff[i];
        ans += count * (count - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}