#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
    int N, H[100009];
    int dp[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];

    dp[1] = 0;
    dp[2] = abs(H[2] - H[1]);
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 2] + abs(H[i] - H[i - 2]), dp[i - 1] + abs(H[i] - H[i - 1]));
    }

    cout << dp[N] << endl;

    int place = N;
    vector<int> Answer;
    while(true) {
        Answer.push_back(place);
        if (place == 1) break;

        if (dp[place - 1] + abs(H[place] - H[place - 1]) == dp[place]) place = place - 1;
        else place = place - 2;
    }

    reverse(Answer.begin(), Answer.end());

    for (int i = 0; i < Answer.size(); i++) {
        cout << Answer[i] << " ";
    }
    cout << endl;

    return 0;
}