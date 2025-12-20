#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> tree(N);
    for (for int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    
    return 0;
}