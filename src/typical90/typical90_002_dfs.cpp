#include<iostream>
#include<functional>
#include<string>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    s.reserve(n);
    function<void(int, int)> dfs = [&](int open, int close) {
        if (s.size() == n) {
            cout << s << endl;
            return 0;
        }
        if (open < n/2) {
            s.push_back('(');
            dfs(open+1, close);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            dfs(open, close+1);
            s.pop_back();
        }
        return 0;
    };
    dfs(0, 0);
    return 0;
}