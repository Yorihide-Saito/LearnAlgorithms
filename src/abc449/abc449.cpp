#include<iostream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    string S;
    cin >> S;

    int ml = 0, mr = L;
    int ans = 0;
    for(;;) {
        cout << ml << ' ' << mr << endl;
        if (S[mr] == S[ml]) {
            ans++;
        }
        if (mr - ml > R) {
            ml++;
            mr = ml + L;
            cout << "tmp: " << ml << ' ' << mr << endl;
        }
        else if (mr - ml <= R && mr < S.size()) {
            mr++;
        }
        else if (mr = S.size() && mr - ml < L) {
            ml++;
        }
        if (mr > S.size() && mr - ml > L) break;
    }

    cout << ans << endl;

    return 0;
}