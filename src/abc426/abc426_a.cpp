#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    vector<string> versions = {"Ocelot", "Serval", "Lynx"};
    unordered_map<string, int> position;

    for (int i = 0; i < versions.size(); i++) {
        position[versions[i]] = i;
    }

    string x, y; cin >> x >> y;

    if (position[x] >= position[y]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}