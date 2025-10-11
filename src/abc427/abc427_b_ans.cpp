#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int f(int i) {
    int result = 0;
    while(i) {
        result += i % 10;
        i /= 10;
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