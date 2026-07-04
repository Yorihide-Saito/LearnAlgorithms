#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;
    cout << ((A > B * 2 / 3) ? "Yes" : "No") << endl;
    return 0;
}