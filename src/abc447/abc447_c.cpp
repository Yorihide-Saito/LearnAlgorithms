#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;
    // 番兵として、0 を最後に配置する
    S.push_back(0);
    T.push_back(0);

    // 直前の A の数、今の数の識別子（'A' を引くため）
    vector<pair<int, int>> s_vec, t_vec;
    int A_counter = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'A') A_counter++;
        else {
            s_vec.emplace_back(A_counter, S[i] - 'A');
            A_counter = 0;
        }
    }
    A_counter = 0;
    for (int j = 0; j < T.size(); j++) {
        if(T[j] == 'A') A_counter++;
        else {
            t_vec.emplace_back(A_counter, T[j] - 'A');
            A_counter = 0;
        }
    }

    // サイズが異なる場合は、一致することはないので -1
    if (s_vec.size() != t_vec.size()) {
        cout << "-1\n";
        return 0;
    }

    // 文字が一致する場合は、直前のAの数の差分を取得してそれを ans に加算する。
    int ans = 0;
    for (int i = 0; i < s_vec.size(); i++) {
        int s_pa = s_vec[i].first, t_pa = t_vec[i].first;
        int s_c = s_vec[i].second, t_c = t_vec[i].second;
        if (s_c != t_c) {
            cout << "-1\n";
            return 0;
        }

        ans += abs(s_pa - t_pa);
    }
    cout << ans << "\n";
    return 0;
}