#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    short N;
    vector<short> group;

    DisjointSet(short n) : N(n), group(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    short find(short n) {
        short g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(short p, short q) {
        short gp = find(p);
        short gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    short M;
    cin >> M;
    DisjointSet ds(N);
    vector<short> enemies(N, -1);
    short group_cnt = N;
    for (int i = 0; i < M; i++) {
        char cmd;
        short p, q;
        cin >> cmd >> p >> q;
        p--;
        q--;
        if (cmd == 'F') {
            if (ds.merge(p, q)) {
                group_cnt--;
            }
        } else {
            if (enemies[p] != -1) {
                if (ds.merge(enemies[p], q)) {
                    group_cnt--;
                }
            }
            if (enemies[q] != -1) {
                if (ds.merge(enemies[q], p)) {
                    group_cnt--;
                }
            }
            enemies[p] = q;
            enemies[q] = p;
        }
    }
    cout << group_cnt << "\n";
    return 0;
}
