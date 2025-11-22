#include<iostream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;

ll f(ll x, ll y) {
    int t = y;
    while(t > 0) {
        x *= 10;
        t /= 10;
    }
    return x + y;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A;
    for (int i = 0 ; i < N; i++) cin >> A[i];


    return 0;
}