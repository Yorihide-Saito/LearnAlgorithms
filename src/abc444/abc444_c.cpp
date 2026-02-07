#include<iostream>
#include<string>
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
    vector<int> V;
    V.push_back(A.back());
    V.push_back(A.front() + A.back());

    for (auto l : V) {
        int i = 0, j = A.size() - 1;
        bool ok = true;
        while(i < j) {
            if (A[i] == l) { i++; continue; }
            if (A[j] == l) { j--; continue; }
            if (A[i] + A[j] != l) { ok = false; break; }
            i++; j--;
        }
        if (ok && i == j && A[i] != l) ok = false;
        if (ok) cout << l << " ";
    }
    cout << endl;
    return 0;
}