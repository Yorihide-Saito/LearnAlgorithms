#include<iostream>
#include<set>
using namespace std;

int main() {
    int N; cin >> N;
    int d[110];
    for (int i = 0; i < N; i++) cin >> d[i];

    set<int> values;
    for (int i = 0; i < N; i++) values.insert(d[i]);

    cout << values.size() << endl;
    return 0;
}