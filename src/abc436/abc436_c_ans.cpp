#include<iostream>
#include<unordered_set>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
    ll N;
    int M;
    cin >> N >> M;

    auto key = [&](int r, int c) -> ull {
        return (ull)(unsigned) r << 32 | (unsigned)c;
    };

    unordered_set<ull> st;
    st.reserve((size_t)M * 2);
    st.max_load_factor(0.7f);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c;
        bool ok = true;
        for (int j = r - 1; j <= r + 1 && ok; j++) {
            for (int k = c - 1; k <= c + 1; k++) {
                if (st.count(key(j, k))) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) st.insert(key(r, c)), ans++;
    }
    cout << ans << endl;
    return 0;
}