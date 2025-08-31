#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 0, y = 0;

    int ans = (x + y) % 12;
    if (ans == 0) ans = 12;
    cout << ans << '\n';
}