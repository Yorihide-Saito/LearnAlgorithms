#include<iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N, 0), b(N, 0);
    for (int n = 0; n < N; n++) {
        cin >> a[n] >> b[n];
    }

    int M;
    cin >> M;
    vector<string> S(M, "");
    // データの持ち方の場合、ループの多重構造でTLEが発生するため有効なアルファベットの配列を持つ
    vector<vector<bool>> vec_ans(N, vector<bool>(26, false));
    for (int m = 0; m < M; m++) {
        cin >> S[m];
        for (int n = 0; n < N; n++) {
            if (a[n] == S[m].size()) {
                // vec_ans に入力された文字列の可能な文字
                vec_ans[n][S[m][b[n] - 1] - 'a'] = true;
            }
        }
    }

    for (int m = 0; m < M; m++) {
        bool is_ok = true;

        if (S[m].size() != N) {
            is_ok = false;
        } else {
            for (int n = 0; n < N; n++) {
                if (!vec_ans[n][S[m][n] - 'a']) {
                    is_ok = false;
                    break;
                }
            }
        }
        if (is_ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}