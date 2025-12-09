#include<iostream>
#include<vector>
#include<stack>
#include<numeric>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    int tmp = gcd(A, (gcd(B, C)));

    cout << (ll)((A / tmp) - (ll)1) + ((B / tmp) - (ll)1) + ((C / tmp)- (ll)1) << endl;
    return 0;
}