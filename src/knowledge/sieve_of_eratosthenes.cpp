#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

using int_64 = long long;

int main() {
    long long N; cin >> N;
    long long L = (long long )sqrtl(N);
    // +1 する理由は、素数の1を[1]として格納したいため。
    vector<bool> is_prime(L+1, true);
    is_prime[0] = is_prime[1] = false;

    // この部分がエラトステネスの古い部分
    for (long long i = 2; i <= L; i++) {
        if(is_prime[i]) {
            for (long long x = i * i; x <= L; x += i) {
                is_prime[x] = false;
            }
        }
    }

    // ここは配列の各ますが上で素数かどうか判定しているので、その値を取ってやる。
    vector<long long> primes;
    primes.reserve(800000);
    for (long long x = 2; x <= L; x++) {
        if (is_prime[x]) primes.push_back(x);
    }

    // これはただの出力コード。
    for (long long x = 0; x < primes.size(); x++) {
        cout << primes[x] << " ";
    }
    cout << endl;
    return 0;
}