#include<iostream>
#include<vector>
#include<utility>
#include<stack>
using namespace std;

const int INF = 100000000;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> a;

    int A;
    cin >> A;
    int pre = A, count = 1;
    for (int i = 1; i < N; i++) {
        cin >> A;
        if (pre == A) {
            count++;
        } else {
            a.emplace_back(pre, count);
            count = 1;
        }
        pre = A;
    }

    a.emplace_back(A, count);

    stack<pair<int, int>> st;

    for (auto [k, v] : a) {
        v %= 4;
        if (v == 0) continue;

        if (!st.empty() && st.top().first == k) {
            st.top().second = (st.top().second + v) % 4;
            if (st.top().second == 0) {
                st.pop();
            }
        } else {
            st.push({k, v});
        }
    }

    long long ans = 0;
    while(!st.empty()) {
        auto p = st.top();
        ans += p.second;
        st.pop();
    }
    cout << ans << endl;
    return 0;
}