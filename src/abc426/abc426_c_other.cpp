#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;

    vector<int> mem(n + 1, 1);
    int pre = 1;

    while(q--) {
        int x, y; cin >> x >> y;
        if (pre > x) {
            cout << "0" << endl;
            continue;
        }

        int count = 0;
        for (int i = pre; i <= x; i++) count += mem[i];
        mem[y] += count;
        pre = x+1;

        cout << count << endl;
    }
    return 0;
}