#include<iostream>
#include<algorithm>
using namespace std;

int T;
long long a, b, c;

int main() {
    cin >> T;

    for (long long i = 0; i < T; i++) {
        cin >> a >> b >> c;

        if(a == 0 || c == 0){
            cout << 0 << endl;
        } else if (a > b && c > b && a > c) {
            cout << min(a, a - c) << endl;
        }  else if (a > b && c > b && c > a) {
            cout << min(c, c - a) << endl;
        } else {
            cout << min(a, c) << endl;
        }
    }
    return 0;
}