#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    unordered_map<ll, ll> A;
    ll sum = 0;
    for (int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        A[tmp]++;
        sum += tmp;
    }

    vector<ll> sum_a;
    for (auto [k, v] : A) {
        sum_a.push_back(k * v);
    }
    sort(sum_a.rbegin(), sum_a.rend());
    for (int i = 0; i < K && i < sum_a.size(); i++) {
        sum -= sum_a[i];
    }
    cout << sum << endl;
    return 0;
}