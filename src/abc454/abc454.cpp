#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

string solve(const string S) {
    vector<vector<char>> stack;
    stack.push_back({});

    for(char c : S) {
        if(c == '(') stack.push_back({});
        else if (c == ')') {
            if (stack.size() <= 1) stack.back().push_back(')');
            else {
                vector<char> tmp = stack.back();
                stack.pop_back();

                auto isAll_x = [](const vector<char>& v) {
                    for (auto c : v) {
                        if (c != 'x') return false;
                    }
                    return true;
                };
                if (isAll_x(tmp) && tmp.size() == 2) {
                    for (char ch : tmp) stack.back().push_back(ch);
                } else {
                    stack.back().push_back('(');
                    for (char ch : tmp) stack.back().push_back(ch);
                    stack.back().push_back(')');
                }
            }
        }
        else {
            stack.back().push_back(c);
        }
    }
    string result;
    for (char c : stack[0]) result += c;
    return result;
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        string A, B;
        cin >> A >> B;
        cout << (solve(A) == solve(B) ? "Yes" : "No") << endl;;
    }
    return 0;
}