#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s; cin >> s;
    string prefix = "", suffix = "";
    int s_size = s.size();
    for (int i = 0; i < s_size / 2; i++) {
        prefix.push_back(s[i]);
        suffix.push_back(s[s_size - i - 1]);
    }

    reverse(suffix.begin(), suffix.end());
    cout << prefix << suffix << endl;
    return 0;
}