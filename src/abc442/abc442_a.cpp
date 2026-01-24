#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;

    bool is_sound = false;
    int volume = 0;

    while (Q--) {
        int A;
        cin >> A;

        if (A == 1) {
            volume++;
        } else if (A == 2) {
            if (volume >= 1) {
                volume--;
            }
        } else if (A == 3) {
            is_sound != is_sound;
        }

        if (is_sound == true && volume >= 3) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}