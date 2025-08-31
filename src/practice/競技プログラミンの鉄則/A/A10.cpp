#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, a = 0; cin >> n;
    vector<int> listA(n + 2, 0), lmax(n + 2, 0), rmax(n + 2, 0);

    for(int i = 1; i <= n; i++){
        cin >> a;
        listA[i] = a;
    }

    for(int i = 1; i <= n; i++) {
        lmax[i] += max(lmax[i - 1], listA[i]);
        rmax[n + 1 - i] += max(rmax[n + 1 - i + 1], listA[n + 1 - i]);
    }

    // 検証用の出力
    for(int i = 1; i <= n; i++) {
        cout << lmax[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
        cout << rmax[i] << " ";
    }
    cout << "\n";

    int d; cin >> d;
    int l, r;
    for (int i = 0; i < d; i++){
        cin >> l >> r;
        cout << max(lmax[l - 1], rmax[r + 1]) << "\n";
    }
    return 0;
}