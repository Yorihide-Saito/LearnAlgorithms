#include<iostream>
using namespace std;

int main(){
    int A, B; cin >> A >> B;
    bool ans = false;

    for(int i = A; i <= B; i++) {
        if(100 % i == 0) {
            ans = true;
            break;
        }
    }

    if(ans == true) cout << "Yes" << endl;
    else cout << "No";

    return 0;
}