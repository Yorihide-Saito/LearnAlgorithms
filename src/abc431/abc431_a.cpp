#include<iostream>
using namespace std;

int main() {
    int H, B; cin >> H >> B;
    int diff = H - B;
    if (diff >= 0) cout << diff << endl;
    else cout << "0" << endl;
    return 0;
}