#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    while(N % M != 0) {
        M = N % M;
        ans++;
    }
    cout << ++ans << endl;
    return 0;
}