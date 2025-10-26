#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

int main() {
    int N, C;
    ll M;
    cin >> N >> M >> C;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // 圧縮コード（区間圧縮）
    // 人がいない箇所を gap として圧縮している。
    sort(A.begin(), A.end());
    // 人のいるポジションを管理する。
    vector<ll> pos; pos.reserve(N);
    // ポジションに対する人の人数を管理する。↑ の pos とは紐づいている。
    vector<int> cnt; cnt.reserve(N);
    for (int i = 0; i < N;) {
        int j = i + 1;
        while(j < N && A[j] == A[i]) j++;
        pos.push_back(A[i]);
        cnt.push_back(j - i);
        i = j;
    }
    int K = (int)pos.size();

    // 人がいる区間の差分を取り出している。
    vector<ll> gap(K);
    for(int i = 0; i < K; i++) {
        ll nxt = (i + 1 < K ? pos[i + 1] : pos[0] + M);
        gap[i] = nxt - pos[i];
    }

    // この時点で保持しているデータは下記となる。
    // pos: 人がいるポジション
    // cnt: ポジションに対する人の人数
    // gap: ポジション感の区間差
    //
    // 例えば、1 2 3 2 2 1 のような人の配置が来た場合は下記のようになる。
    // pos: 1, 2, 3
    // cnt: 2, 3, 1
    // gap: 1, 1, 1

    // cnt を 2倍にした配列（これを作るのは今回の問題が環状の例であるから）
    vector<int> cnt2(2 * K);
    for (int i = 0; i < 2 * K; i++) cnt2[i] = cnt[i % K];

    // __int128 は 128bit 整数。標準C++ではない拡張型
    // long long に回答は収まると思うけど、__int128 を推奨と ChatGPT がおっしゃっていた。
    // オーバーフローの可能性をなくすために __int128 を利用する。
    __int128 ans = 0;
    ll sum = 0;
    // r を１から始める理由は、各区間 i では次に会う点 i+1 から数えたい → 初回 l=0 に合わせて r=1, sum=0 で開始
    int r = 1;

    // しゃくとり法
    // 今回は、0.5 から開始する。つまり今のポジションの次の人から加算するため最終的な l + 1。
    for (int l = 0; l < K; l++) {
        // C（指定に人数）を超えるまで r を加算する。
        while(sum < C) {
            sum += cnt2[r];
            r++;
        }
        // Yi は問題文から取った。
        ll Yi = sum;
        ans += (__int128)gap[l] * Yi;
        // l が移動するたびに削除するようにする。r を 1 から始めるにあたり + 1 をする。
        sum -= cnt2[l + 1];
    }

    cout << (ll)ans << endl;
    return 0;
}