#include<iostream>
#include<vector>
#include<utility>
#include<iomanip>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<ll, int>> sum_count(M, {0LL, 0});

    while(N--) {
        int A, B;
        cin >> A >> B;
        A--;
        sum_count[A].first = sum_count[A].first + B;
        sum_count[A].second++;
    }

    for (int i = 0; i < M; i++) {
        double ans = (double)sum_count[i].first / sum_count[i].second;
        cout << fixed << setprecision(16) << ans << endl;
    }
    return 0;
}