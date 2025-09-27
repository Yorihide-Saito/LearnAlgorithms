#include<iostream>
#include<cmath>
using namespace std;

int main (){
    int A, B; cin >> A >> B;
    long long ans = (pow(A, B) + pow(B, A));
    cout << ans << endl;
    return 0;
}