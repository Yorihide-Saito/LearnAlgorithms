#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        char cc = s[n/2];
        int sum_char_count = 0, all_count = 0;
        for (int i = 0; i <= n / 2; i++) {
            if(s[i] == cc) sum_char_count++;
            else {
                all_count += (sum_char_count * 2) + 1;
                sum_char_count = 0;
            }
        }

        sum_char_count = 0;
        for (int i = n-1; i > (n + 1) / 2; i--) {
            if(s[i] == cc) sum_char_count++;
            else {
                all_count += (sum_char_count * 2) + 1;
                sum_char_count = 0;
            }
        }

        cout << all_count << endl;
    }
    return 0;
}