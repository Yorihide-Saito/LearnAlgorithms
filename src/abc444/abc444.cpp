#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;

    sort(A.begin(), A.end());
    int size_A = A.size();

    map<ll, ll> m;
    for (int i = 0; i < size_A; i++) {
        m[A[i]] += 1;
    }

    int current_k = 0;
    int sum_v = 0;
    for (auto [k, v] : m) {
        sum_v += v;
        for (int i = current_k; i < k; i++) {
            cout << sum_v;
        }
        current_k = k;
    }

    cout << endl;
    return 0;
}