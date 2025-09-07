#include<iostream>
using namespace std;

int main() {
    int world, stage;
    char ws[4];
    cin >> ws;
    world = ws[0] - '0';
    stage = ws[2] - '0';

    if (stage < 8) {
        cout << world << '-' << stage + 1 << endl;
    } else if (stage == 8 && world < 8) {
        cout << world + 1 << '-' << '1' << endl;
    }

    return 0;
}