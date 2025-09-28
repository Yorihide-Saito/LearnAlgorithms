#include<iostream>
#include<vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N+1, -1);
    vector<int> used(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];

    int addMax = 0;
    for (int i = 1; i <= N; i++) addMax += i;

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] != -1)  {
            if (used[A[i]]) {
                cout << "No" << endl;
                return 0;
            }
            addMax -= i;
            used[A[i]] = 1;
        }
        else count += i;
    }
    cout << "Yes" << endl;
    vector<int> ans;
    for (int i = 1; i <= N; i++) if (!used[i]) ans.push_back(i);
    int index = 0;
    for (int i = 1; i <= N; i++) if(A[i] == -1) A[i] = ans[index++];
    for (int i = 1; i <= N; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}