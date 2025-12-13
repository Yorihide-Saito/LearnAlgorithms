#include<iostream>
#include<string>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    for(int i = 0; i < N - (int)S.size(); i++) {
        cout << 'o';
    }
    cout << S << endl;
    return 0;
}