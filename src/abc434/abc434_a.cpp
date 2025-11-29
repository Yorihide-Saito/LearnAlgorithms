#include<iostream>
using namespace std;
using ll = long long;

int main() {
    int W, B;
    cin >> W >> B;

    W = W * 1000;
    int count = 0, nB = 0;
    do {
        nB = ++count * B;
    } while(!(W < nB));

    cout << count << endl;
    return 0;
}