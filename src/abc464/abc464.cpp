#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<int> kind(N + 1);
    vector<vector<pair<int, int>>> events(M + 1);

    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (kind[A] == 0) {
            ans++;
        }
        kind[A]++;
        events[B].emplace_back(A, C);
    }

    for (int i = 1; i <= M; i++) {
        for (auto [a, c]: events[i]) {
            kind[a]--;
            if (kind[a] == 0) ans--;
            if (kind[c] == 0) ans++;
            kind[c]++;
        }
        cout << ans << endl;
    }
    return 0;
}