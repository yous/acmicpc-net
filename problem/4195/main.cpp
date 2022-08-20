#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<int> group;
    vector<int> cnt;

    DisjointSet(int n) : N(n), group(n), cnt(n, 1) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            cnt[gq] += cnt[gp];
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        int F;
        cin >> F;
        DisjointSet ds(F * 2);
        map<string, int> name_map;
        int name_cnt = 0;
        for (int i = 0; i < F; i++) {
            string name1, name2;
            int name1_idx, name2_idx;
            cin >> name1 >> name2;
            auto it = name_map.find(name1);
            if (it != name_map.end()) {
                name1_idx = it->second;
            } else {
                name_map[name1] = name_cnt;
                name1_idx = name_cnt;
                name_cnt++;
            }
            it = name_map.find(name2);
            if (it != name_map.end()) {
                name2_idx = it->second;
            } else {
                name_map[name2] = name_cnt;
                name2_idx = name_cnt;
                name_cnt++;
            }
            ds.merge(name1_idx, name2_idx);
            cout << ds.cnt[ds.find(name1_idx)] << "\n";
        }
    }
    return 0;
}
