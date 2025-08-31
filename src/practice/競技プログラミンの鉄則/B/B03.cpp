#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    bool ans = false;

    for(int i = 0; i < N; i++) cin >> A[i];

    for(int x = 0; x < N; x++) {
        for(int y = x+1; y < N; y++) {
            for(int z = y+1; z < N; z++) {
                if(A[x] + A[y] + A[z] == 1000) ans = true;
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}