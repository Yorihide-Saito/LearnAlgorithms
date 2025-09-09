#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

using int64 = long long;
// 拡張整数型。
using i128 = __int128_t;

int main() {
    long long N;
    if (!(cin >> N)) return 0;

    // a^2 < b < c^2 の場合なので、Nの平方根を取る。long long にしているのは、N が 10^8であるため。
    long long L = (long long) sqrtl((long double)N);

    // 探索したい値は L が最大ということがわかるので、prime という配列を作成する。
    // L+1 である理由は、予備の領域。
    vector<int> is_prime(L + 1, true);

    // 0, 1 は素数ではないので、false とする。
    is_prime[0] = is_prime[1] = false;

    // 下記の for 分で、素数でないものを弾いていく。
    // エラトステネスのふるいの実装。
    // 素数の場合はその倍数は素数ではないため弾いていく。
    for (long long p = 2; p * p <= L; p++){
        if (is_prime[p]) {
            for (long long q = p * p; q <= L; q += p) is_prime[q] = false;
        }
    }

    // 配列 primes で 800000 の領域を確保する。
    // push_back で素数の配列を作成するために、メモリ確保の push_back する。
    vector<int> primes;
    primes.reserve(80000);
    for (int x = 2; x <= L; x++) if (is_prime[x]) primes.push_back(x);


    // pi は素数の個数の配列を作成している。
    // 例えば、pi[10] の場合は 4個 {2, 3, 5, 7} になる。
    vector<int> pi(L+1, 0);
    for(int x = 1; x <= L; x++) {
        pi[x] = pi[x - 1] + (is_prime[x] ? 1 : 0);
    }
    auto prime_count_leq = [&](long long x) -> int {
        if (x < 0) return 0;
        if (x > L) x = L;
        return pi[(int)x];
    };

    long long ans = 0;

    for (int idx_c = 0; idx_c < (int)primes.size(); idx_c++) {
        long long c = primes[idx_c];

        // 先に N/cc をすることで、a^2 * b の組み合わせのみを確認できるようにする。
        // 計算時間の削減。
        long long K;
        {
            i128 cc = (i128)c * (i128)c;
            if(cc > (i128)N) break;
            K = (long long)((i128)N / cc);
        }

        // a を求める。
        for (int idx_a = 0; idx_a < idx_c; idx_a++) {
            long long a = primes[idx_a];


            // 下限チェックを早期でbreakする処理。
            // b は少なくとも b >= a+1 になるため、a^2 * a+1 が K(a^2 * b)を超える場合は処理を打ち切る。
            i128 lhs = (i128)a * (i128)a * (i128)(a + 1);
            if (lhs > (i128)K) break;

            // b を求める
            // b_max は、b < c との条件があるため。
            long long bmax_by_K = (long long )((i128)K / ((i128)a * (i128)a));
            long long b_max = min(bmax_by_K, c-1);

            if (b_max <= a) continue;

            int add = prime_count_leq(b_max) - prime_count_leq(a);
            if(add > 0) ans += add;
        }
    }

    cout << ans << endl;
    return 0;
}