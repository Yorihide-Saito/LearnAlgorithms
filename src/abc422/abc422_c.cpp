#include<iostream>
#include<algorithm>
using namespace std;

int T;
long long a, b, c;

int main() {
    cin >> T;

    for (long long i = 0; i < T; i++) {
        cin >> a >> b >> c;

        long long total = a + b + c;
        cout << min({a, c , total/3}) << endl;
    }
    return 0;
}