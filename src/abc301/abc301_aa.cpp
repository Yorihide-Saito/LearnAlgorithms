#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int N; string s;
    cin >> N >> s;
    int t = count(s.begin(), s.end(), 'T');
    int a = N - t;

    if (t > a) cout << "T" << endl;
    else if (a > t) cout << "A" << endl;
    else cout << char('T' + 'A' - s.back()) << endl;
    return 0;
}