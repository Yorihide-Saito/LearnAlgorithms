#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string X; cin >> X;
    vector<int> vX(X.size(), 0);
    for (int i = 0; i < X.size(); i++) {
        vX[i] = X[i] - '0';
    }
    sort(vX.begin(), vX.end());

    int count = 1;
    while(vX[0] == 0 && count <= vX.size()) {
        if (vX[count] != 0){
            swap(vX[0], vX[count]);
        }
        count++;
    }
    for (int i = 0; i < vX.size(); i++) {
        cout << vX[i];
    }
    cout << endl;
    return 0;
}