#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    map<string, int> map_subset;
    for (int i = 0; i < n - k + 1; i++) {
        string tmp = s.substr(i, k);
        map_subset[tmp]++;
    }

    int count = 0;
    for (auto &p : map_subset) {
        count = max(count, p.second);
    }

    cout << count << endl;
    for (auto &p : map_subset) {
        if (p.second == count) {
            cout << p.first << " ";
        }
    }
    cout << endl;

    return 0;
}