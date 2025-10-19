#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isEnabled(string &s) {
    int s_size = s.size();
    int count = 0;
    return false;
}

int main() {
    int q; cin >> q;
    string s;

    vector<int> counter = {0};
    vector<int> minPref  = {0};
    while(q--) {
        int command; cin >> command;
        if (command == 1) {
            char c; cin >> c;
            s.push_back(c);

            int pref = counter.back();
            if (c == '(') counter.push_back(pref + 1);
            if (c == ')') counter.push_back(pref - 1);
            minPref.push_back(min(minPref.back(), pref));
        }
        else  {
            char c = s.back();
            s.pop_back();
            counter.pop_back();
            minPref.pop_back();
        }

        if (counter.back() == 0 && minPref.back() >= 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}