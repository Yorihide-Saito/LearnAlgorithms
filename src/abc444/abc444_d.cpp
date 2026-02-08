#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    int maxA = A.back();
    vector<int> diff(maxA + 1);
    for (int i = 0; i < A.size(); i++) {
        diff[0] += 1;
        diff[A[i]] -= 1;
    }

    vector<int> c(maxA + 1);
    int current = 0;
    for (int i = 0; i < maxA; i++) {
        current += diff[i];
        c[i] = current;
    }

    for (int i = 0; i < c.size() - 1; i++) {
        c[i+1] += c[i] / 10;
        c[i] = c[i] % 10;
    }

    int i = c.size() - 1;
    while(i > 0 && c[i] == 0) i--;
    for(; i >= 0; i--) cout << c[i];
    cout << endl;
    return 0;
}