#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int f(int i) {
    string s = to_string(i);
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        result += s[i] - '0';
    }
    return result;
}

int main() {
    int a; cin >> a;
    int sum = 1;
    int result = 0;

    a--;
    while(a--) {
        result = f(sum);
        sum += result;
    }
    cout << sum << endl;
    return 0;
}