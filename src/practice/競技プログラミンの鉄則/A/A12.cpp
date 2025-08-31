#include<iostream>
using namespace std;

long long N, K;
long long A[100009];

bool check(long long x) {
    long long sum = 0;
    for (int i = 0; i < N; i++) sum += x / A[i];
    if (sum >= K) return true;
    return false;
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];

    long long Left = 1, Right = 1'000'000'000;
    while(Left < Right) {
        long long Mid = (Left + Right) / 2;
        bool Answer = check(Mid);
        if(Answer == false) Left = Mid + 1;
        if(Answer == true) Right = Mid;
    }

    cout << Left << "\n";
    return 0;
}