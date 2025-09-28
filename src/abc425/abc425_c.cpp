#include<iostream>
#include<string>
#include<vector>
#include <sstream>
#include<algorithm>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> query(3, 0);
    for (int i = 0; i < Q; i++) {
        string line;
        getline(cin >> ws, line);
        istringstream iss(line);
        int x, k = 0;
        while (k < 3 && (iss >> x)) {
            query[k++] = x;
        }

        if (query[0] == 1) {
            rotate(A.begin(), A.begin() + query[1], A.end());
        }
        if (query[0] == 2) {
            int ans = 0;
            for (int i = query[1] - 1; i <= query[2] - 1; i++) {
                ans += A[i];
            }
            cout << ans << endl;;
        }
    }
    return 0;
}