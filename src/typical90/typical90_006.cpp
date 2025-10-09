#include<iostream>
using namespace std;

int main () {
    int N, K;
    string S;
    if (!(cin >> N >> K >> S)) return 0;

    string st; st.reserve(K);
    for (int i = 0; i < N; ++i) {
        while (!st.empty() && st.back() > S[i] && (int)st.size() - 1 + (N - i) >= K) {
            st.pop_back();
        }
        if ((int)st.size() < K) st.push_back(S[i]);
    }
    st.resize(K);
    cout << st << endl;
    return 0;
}