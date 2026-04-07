#include<iostream>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;

int main() {
    vector<pair<int, int>> md = {
        {1, 7},
        {3, 3},
        {5, 5},
        {7, 7},
        {9, 9}
    };
    int M, D;
    cin >> M >> D;
    for (int i = 0; i < md.size(); i++) {
        if (M == md[i].first) {
            if (D == md[i].second) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}