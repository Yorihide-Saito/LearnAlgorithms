#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<deque>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, D;
        cin >> N >> D;
        vector<int> a(N + 1), b(N + 1);
        for (int i = 1; i <= N; i++) cin >> a[i];
        for (int i = 1; i <= N; i++) cin >> b[i];

        deque<pair<int ,ll>> q;
        ll total = 0;
        for (int i = 1; i <= N; i++) {
            q.push_back({i, a[i]});
            total += a[i];

            ll need = b[i];
            while(need > 0) {
                auto &tmp = q.front();
                ll use = min(tmp.second, need);
                tmp.second -= use;
                need -= use;
                total -= use;
                if (tmp.second == 0) q.pop_front();
            }

            int limit = i - D;
            while(!q.empty() && q.front().first <= limit) {
                total -= q.front().second;
                q.pop_front();
            }
        }
        cout << total << endl;
    }
    return 0;
}