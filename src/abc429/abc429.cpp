#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

ll MAX_SIZE = 5 * 1e5;

int main() {
    ll n, m ,c; cin >> n >> m >> c;

    map<ll, int> a;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        a[num]++;
    }

    
    return 0;
}