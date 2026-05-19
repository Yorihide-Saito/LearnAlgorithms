#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
using ll = long long;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> S1;
    priority_queue<long long> S2;
    long long X;
    cin >> X;
    S2.push(X);

    int Q;
    cin >> Q;
    while(Q--) {
        long long A, B;
        cin >> A >> B;
        long long minS2;
        minS2 = S2.top();

        if (A <= minS2) S2.push(A);
        else S1.push(A);
        if (B <= minS2) S2.push(B);
        else S1.push(B);

        if ((int)S2.size() > (int)S1.size() + 1) {
            long long tmp = S2.top();
            S2.pop();
            S1.push(tmp);
        }
        if ((int)S2.size() < (int)S1.size()) {
            long long tmp = S1.top();
            S1.pop();
            S2.push(tmp);
        }
        cout << S2.top() << endl;
    }
    return 0;
}