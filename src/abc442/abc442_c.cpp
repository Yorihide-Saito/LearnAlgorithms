#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 0; i < N; i++) {
        int x = graph[i].size();
        ll other = (ll)N - 1 - (ll)x;
        cout << (other * (other - 1) * (other - 2)) / 6 << ' ';
    }
    cout << endl;
    return 0;
}