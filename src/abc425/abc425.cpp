#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int shift = 0;
    vector<ll> b(n * 2 + 1, 0);
    for (int i = 0; i < n * 2; i++) b[i+1] = b[i] + a[i % n];

    while(q){
        int command; cin >> command;
        if (command == 1) {
            int c; cin >> c;
            shift = (shift + c) % n;
        } else if (command == 2) {
            int l, r; cin >> l >> r;
            l--;
            cout << b[shift + r] - b[shift + l] << endl;
        }
        q--;
    }
}