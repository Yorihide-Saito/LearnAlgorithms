#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    if ((N + 1)/ 2 >= M) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}