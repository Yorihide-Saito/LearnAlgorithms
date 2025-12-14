#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

// abc291_b
// https://atcoder.jp/contests/abc291/tasks/abc291_b

int main() {
    int N; cin >> N;
    int n5 = N * 5;
    int n3 = N * 3;
    vector<int> X(n5, 0);

    for (int i = 0; i < n5; i++) {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    double tmp = 0;
    for (int i = N; i < n5 - N; i++) {
        tmp += X[i];
    }

    printf("%.8f\n", tmp / n3);
}