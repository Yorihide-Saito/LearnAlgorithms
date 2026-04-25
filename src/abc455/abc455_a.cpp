#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A != B && B == C) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}