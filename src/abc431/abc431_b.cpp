#include<iostream>
#include<vector>
using namespace std;

int main() {
    int X; cin >> X;
    int N; cin >> N;
    vector<int> W(N, 0);
    for (int i = 0; i < N; i++) cin >> W[i];
    int Q; cin >> Q;

    int ans = X;
    vector<int> isOn(N, 0);
    while(Q--) {
        int P; cin >> P;
        P--;
        if (isOn[P] == 1) {
            ans -= W[P];
            isOn[P] = 0;
        }
        else {
            ans += W[P];
            isOn[P] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}