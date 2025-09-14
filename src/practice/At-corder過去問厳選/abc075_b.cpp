#include<iostream>
#include<vector>
using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> S(H + 2, vector<char> (W + 2, 0));

    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            cin >> S[h][w];
        }
    }

    for (int h = 1; h <= H; h++) {
        for(int w = 1; w <= W; w++) {
            int count = 0;
            if (S[h][w] == '#') { cout << "#"; continue; }
            else {
                if (S[h-1][w] == '#') count++;
                if (S[h-1][w-1] == '#') count++;
                if (S[h][w-1] == '#') count++;
                if (S[h+1][w-1] == '#') count++;
                if (S[h][w+1] == '#') count++;
                if (S[h+1][w+1] == '#') count++;
                if (S[h+1][w] == '#') count++;
                if (S[h-1][w+1] == '#') count++;
                cout << count;
            }
        }
        cout << endl;
    }
    return 0;
}