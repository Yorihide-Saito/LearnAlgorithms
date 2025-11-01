#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main () {
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;

    vector<int> a_count(N + 1, 0), b_count(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'a') a_count[i] = a_count[i - 1] + 1;
        else a_count[i] = a_count[i - 1];
        if (S[i - 1] == 'b') b_count[i] = b_count[i - 1] + 1;
        else b_count[i] = b_count[i - 1];
    }

    long long ans = 0;
    int r_a = 0, r_b = 0;
    for (int l = 0; l < N; l++) {
        if (r_a <= l) r_a = l + 1;
        if (r_b <= l) r_b = l + 1;

        while(r_a <= N && a_count[r_a] - a_count[l] < A) r_a++;
        while(r_b <= N && b_count[r_b] - b_count[l] < B) r_b++;

        int L = max(l + 1, r_a);
        if (L < r_b) ans += (r_b - L);
    }

    cout << ans << endl;
    return 0;
}