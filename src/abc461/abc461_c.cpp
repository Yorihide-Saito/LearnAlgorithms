#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<vector<long long >> Gems(N + 1);
    for (int i = 0; i < N; i++) {
        long long C, V;
        cin >> C >> V;
        Gems[C].push_back(V);
    }

    vector<long long> max, auther;
    for (int i = 1; i <= N; i++) {
        sort(Gems[i].rbegin(), Gems[i].rend());
        if (Gems[i].empty()) continue;
        max.push_back(Gems[i][0]);
        for (int j = 1; j < Gems[i].size(); j++) {
            auther.push_back(Gems[i][j]);
        }
    }

    long long sum = 0;
    sort(max.rbegin(), max.rend());
    for (int i = 0; i < M; i++) {
        sum += max[i];
    }
    for (int i = M; i < max.size(); i++) {
        auther.push_back(max[i]);
    }

    sort(auther.rbegin(), auther.rend());
    for(int i = 0; i< K - M; i++) {
        sum += auther[i];
    }
    cout << sum << endl;
    return 0;
}