#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int size = S.size();

    vector<int> intS(size, 0);
    for (int i = 0; i < size; i++) {
        intS[i] = S[i] - '0';
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        int l = i;
        int r = i + 1;
        if ((0 <= l && r < size) && intS[l] + 1 == intS[r]) {
            int checkSumL = intS[l];
            int checkSumR = intS[r];
            while((0 <= l && r < size) && intS[l] == checkSumL && intS[r] == checkSumR) {
                count++;
                l--;
                r++;
            }
        }
    }
    cout << count << endl;
    return 0;
}