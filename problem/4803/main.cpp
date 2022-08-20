#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    short N;
    short cnt;
    short cycle_cnt = 0;
    vector<short> group;
    vector<bool> has_cycle;

    DisjointSet(short n) : N(n), cnt(n), group(n), has_cycle(n) {
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
            if (has_cycle[gp] && has_cycle[gq]) {
                cycle_cnt--;
            }
            has_cycle[gq] = (has_cycle[gq] || has_cycle[gp]);
            cnt--;
            return true;
        }
        if (!has_cycle[gp]) {
            has_cycle[gp] = true;
            cycle_cnt++;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    int M;
    int T = 1;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        DisjointSet ds(N);
        for (int i = 0; i < M; i++) {
            short u, v;
            cin >> u >> v;
            ds.merge(u - 1, v - 1);
        }
        cout << "Case " << T << ": ";
        short ans = ds.cnt - ds.cycle_cnt;
        if (ans > 1) {
            cout << "A forest of " << ans << " trees.\n";
        } else if (ans == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "No trees.\n";
        }
        T++;
    }
    return 0;
}
