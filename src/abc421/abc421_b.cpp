#include<bits/stdc++.h>
using namespace std;

long long X, Y;
long long a[100009];

long long rev(long long x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

int main() {
    cin >> X >> Y;
    a[0] = X;
    a[1] = Y;
    for (int i = 2; i < 10; i++) {
        a[i] = rev(a[i-1] + a[i-2]);
    }
    cout << a[9] << "\n";
    return 0;
}