#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int e = 0, w = 0;
    for (char c: S) {
        if (c == 'E') e++;
        if (c == 'W') w++;
    }
    cout << (e < w ? "West" : "East") << endl;
    return 0;
}