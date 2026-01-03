#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int D, N;
    cin >> D >> N;
    int ans = (N - (D % 7)) % D;

    if (ans <= 0) ans += 7;

    cout << ans << endl;
    return 0;
}