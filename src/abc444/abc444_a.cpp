#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string N;
    cin >> N;
    char current_c = N[0];
    for (int i = 1; i < N.size(); i++) {
        if (current_c != N[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}