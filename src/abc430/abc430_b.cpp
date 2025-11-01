#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int main () {
    int N, M; cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    set<string> dict;

    for (int i = 0; i + M <= N; i++) {
        for (int j = 0; j + M <= N; j++) {
            string key;
            for (int k = 0; k < M; k++) {
                key += grid[i + k].substr(j, M);
                key += '\n';
            }
            dict.insert(key);
        }
    }
    cout << dict.size() << endl;
    return 0;
}