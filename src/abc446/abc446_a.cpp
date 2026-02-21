#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    S[0] = S[0] + 32;
    cout << "Of" << S << endl;
    return 0;
}