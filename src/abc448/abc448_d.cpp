#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<unordered_map>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    unordered_map<int, int> cnt;
    vector<string> ans(N);
    int dup = 0;

    auto dfs = [&](auto&& self, int v, int p) -> void {
        // 各ノードに訪ねた瞬間に重複を確認して、重複がある場合は No を格納する
        // 重複を計算するカウント状態を持つ
        // dup は duplicate の略で重複の数をカウントする
        cnt[A[v]]++;
        if (cnt[A[v]] >= 2) dup++;

        ans[v] = (dup > 0 ? "Yes" : "No");

        // DFS 自体の処理
        for (int to : graph[v]) {
            if (to == p) continue;
            self(self, to, v);
        }

        // DFS の終わり戻りの際に今いる地点の重複を削除して戻す
        if (cnt[A[v]] >= 2) dup--;
        cnt[A[v]]--;
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}