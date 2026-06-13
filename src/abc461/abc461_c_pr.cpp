#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    vector<vector<long long>> Gems(N + 1);
    for (int i = 0; i < N; i++) {
        int C; cin >> C;
        long long V; cin >> V;
        Gems[C].push_back(V);
    }

    vector<pair<long long, int>> head, tail;

    for (int i = 1; i <= N; i++) {
        sort(Gems[i].rbegin(), Gems[i].rend());
        if (Gems[i].empty()) continue;
        head.push_back({Gems[i][0], i});
        for (int j = 1; j < Gems[i].size();j++) {
            tail.push_back({Gems[i][j], i});
        }
    }

    sort(head.rbegin(), head.rend());
    long long ans = 0;

    for (int i = 0; i < head.size(); i++) {
        if (i < M) {
            ans += head[i].first;
        }
        else {
            tail.push_back({head[i].first, head[i].second});
        }
    }

    sort(tail.rbegin(), tail.rend());

    for(int i = 0; i < K - M; i++) {
        ans += tail[i].first;
    }

    cout << ans << endl;

    return 0;
}