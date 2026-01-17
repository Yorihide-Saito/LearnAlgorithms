#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> aoki(27, 0), takasi(27, 0);
    string s, t;
    cin >> s;
    for(auto s_a : s) {
        takasi[s_a - 'a'] = 1;
    }
    cin >> t;
    for(auto t_a : t) {
        aoki[t_a - 'a'] = 1;
    }

    int q; cin >> q;
    while(q--) {
        string w; cin >> w;
        bool is_takasi = 1, is_aoki = 1;
        for (auto w_a : w) {
            if (takasi[w_a - 'a'] == 0) {
                is_takasi = 0;
            } else if (aoki[w_a - 'a'] == 0) {
                is_aoki = 0;
            }
        }
        if (is_takasi && is_aoki) {
            cout << "Unknown" << endl;
        } else if (is_takasi) {
            cout << "Takahashi" << endl;
        } else if (is_aoki) {
            cout << "Aoki" << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }

    return 0;
}
