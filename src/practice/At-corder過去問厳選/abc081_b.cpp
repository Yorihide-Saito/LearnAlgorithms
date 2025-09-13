#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N), ANS(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        int a = A[i], count = 0;
        while(a % 2 == 0) {
            a = a / 2;
            count++;
        }
    }
    cout << *min_element(A.begin(), A.end()) << endl;
    return 0;
}