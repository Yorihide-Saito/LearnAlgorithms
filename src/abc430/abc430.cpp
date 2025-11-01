#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main () {
    int N; cin >> N;
    vector<long long> X(N), sorted_X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    sorted_X = X;
    sort(sorted_X.begin(), sorted_X.end());

    vector<unordered_map<long long, long long>> dp(N + 1);
    for (int i = 0; i <= N; i++) {
        dp[i] = {sorted_X, 0};
    }

    dp[0].emplace_back(0, 0);

    for (int i = 1; i <= N; i++) {
    }
    return 0;
}