#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    string s; cin >> s;

    unordered_map<char, int> mem;
    for (int i = 0; i < (int)s.size(); i++) mem[s[i]]++;

    for (int i = 0; i < (int)s.size(); i++) {
        if (mem[s[i]] != 1) continue;
        cout << s[i] << endl;
        return 0;
    }
    return 0;
}