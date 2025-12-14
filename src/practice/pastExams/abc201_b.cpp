#include<iostream>
#include<map>
#include<string>
#include<functional>
using namespace std;

// abc201_b
// https://atcoder.jp/contests/abc201/tasks/abc201_b

int main() {
    int N; cin >> N;
    map<int, string, greater<int>> mounten;
    for (int i = 0; i < N; i++) {
        int T;
        string S;
        cin >> S >> T;
        mounten.insert({T, S});
    }

    auto it = mounten.begin();
    it++;
    cout << (*it).second << endl;
    return 0;
}