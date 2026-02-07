#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    int count = 0;

    for (int i = 1; i <= N; i++) {
        int sum_i = i % 10;
        int s = i / 10;
        while(s >= 10) {
            sum_i += s % 10;
            s = s / 10;
        }
        sum_i += s;
        if (sum_i == K) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}