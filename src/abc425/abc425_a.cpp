#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += pow(-1, i) * pow(i, 3);
    }
    cout << ans << endl;
    return 0;
}