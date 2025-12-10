#include<iostream>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    vector<int> node_color(N, -1);
    vector<int> visited(N, 0);
    stack<int> st;

    st.push(0);
    node_color[0] = 0;
    while(!st.empty()) {
        int c = st.top();
        st.pop();
        for (int n : tree[c]) {
            if (visited[n]) continue;
            visited[c] = 1;
            node_color[n] = 1 - node_color[c];
            st.push(n);
        }
    }

    vector<int> group0, group1;
    for (int i = 0; i < N; i++) {
        if (node_color[i] == 0) group0.push_back(i + 1);
        else group1.push_back(i + 1);
    }

    vector<int> &big = (group0.size() >= group1.size() ? group0 : group1);

    int need = N / 2;
    for (int i = 0; i < need; i++) {
        if (i) cout << ' ';
        cout << big[i];
    }
    cout << endl;
    return 0;
}