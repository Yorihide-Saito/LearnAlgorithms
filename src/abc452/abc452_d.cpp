#include<iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    string S, T;
    cin >> S;
    cin >> T;

    // 前処理
    // 次の文字に遷移できるかを確認する入れる
    vector<vector<int>> nxt(S.size() + 1, vector<int>(26, INF));
    for (int c = 0; c < 26; c++) nxt[S.size()][c] = INF;
    for (int i = S.size() - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i] - 'a'] = i;
    }

    ll ans = 0;
    for (int l = 0; l < S.size(); l++) {
        int current = l;
        int last = -1;
        bool is_ok = true;

        for (char c : T) {
            if (current > S.size()) {
                is_ok = false;
                break;
            }
            if (nxt[current][c - 'a'] == INF) {
                is_ok = false;
                break;
            }
            last = nxt[current][c - 'a'];
            current = nxt[current][c - 'a'] + 1;
        }

        if (is_ok) ans += last - l;
        else ans += S.size() - l;
    }

    cout << ans << endl;
    return 0;
}