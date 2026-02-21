#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    if (S[0] == S[S.size()-1]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}