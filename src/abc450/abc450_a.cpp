#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    for (int i = N; i > 0; i--) {
        cout << i;
        if (i != 1) cout << ",";
    }
    cout << "\n";
    return 0;
}