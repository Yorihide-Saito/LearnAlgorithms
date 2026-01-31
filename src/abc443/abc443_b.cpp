#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    int sum = 0, count = 0;
    sum += N;
    while(sum < K) {
        count++;
        sum += N + count;
    }
    cout << count << endl;
    return 0;
}