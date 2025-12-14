#include<iostream>
#include<string>
using namespace std;

// abc350_a
// https://atcoder.jp/contests/abc350/tasks/abc350_a
int main() {
    string S;
    cin >> S;

    auto num = [&](char a, char b, char c) -> int {
        return (a - '0') * 100 + (b - '0') * 10 + (c - '0') * 1;
    };

    int num_3 = num(S[3], S[4], S[5]);
    if ((1 <= num_3 && num_3 <= 315) || (317 <= num_3 && num_3 <= 349)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}