#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A;
    A.reserve(N);

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());

    int totalA = 0, totalB = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) totalA += A[i];
        else totalB += A[i];
    }

    cout << totalA - totalB << endl;
    return 0;
}