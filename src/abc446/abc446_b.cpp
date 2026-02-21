#include<iostream>
#include<string>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> juice(M + 1, 0);
    while(N--) {
        int L;
        cin >> L;
        bool isOk = 0;
        for (int i = 0; i < L; i++) {
            int req;
            cin >> req;
            if (!juice[req] && !isOk) {
                cout << req << endl;;
                juice[req] = 1;
                isOk = 1;
            }
        }
        if (!isOk) cout << '0' << endl;
    }
    return 0;
}