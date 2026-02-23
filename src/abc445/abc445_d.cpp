#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];
    }

    map<int, vector<int>> map_h, map_w;
    for (int i = 0; i < N; i++) {
        map_h[h[i]].push_back(i);
        map_w[w[i]].push_back(i);
    }


    vector<pair<int, int>> pos(N);
    int r = 1, c = 1;
    vector<int> used(N, 0);
    for (int i = 0; i < N; i++) {
        auto it = map_h.find(H);
        if (it != map_h.end()) {
            vector<int> &tmp = it->second;
            while(tmp.size() && used[tmp.back()]) tmp.pop_back();
            if(!tmp.empty()) {
                int is_part_num = tmp.back();
                tmp.pop_back();
                pos[is_part_num] = {r, c};
                W -= w[is_part_num];
                c += w[is_part_num];
                used[is_part_num] = 1;
                continue;
            } else {
                map_h.erase(it);
            }
        }
        auto it2 = map_w.find(W);
        if(it2 != map_w.end()) {
            vector<int> &tmp = it2->second;
            while(tmp.size() && used[tmp.back()]) tmp.pop_back();
            if(tmp.empty()) {
                map_w.erase(it2);
                break;
            }
            int is_part_num = tmp.back();
            tmp.pop_back();
            pos[is_part_num] = {r, c};
            H -= h[is_part_num];
            r += h[is_part_num];
            used[is_part_num] = 1;
        } else {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << pos[i].first << ' ' << pos[i].second << endl;
    }
    return 0;
}