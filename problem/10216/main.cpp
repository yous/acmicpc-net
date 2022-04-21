#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<short> group;

    DisjointSet(short n) : group(n) {
        for (int i = 0; i < n; i++) {
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
            group[gq] = gp;
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
        short N;
        cin >> N;
        vector<tuple<short, short, short>> areas(N);
        DisjointSet ds(N);
        for (auto& [x, y, r] : areas) {
            cin >> x >> y >> r;
        }
        short ans = N;
        for (int i = 0; i < N - 1; i++) {
            auto [x1, y1, r1] = areas[i];
            for (int j = i + 1; j < N; j++) {
                auto [x2, y2, r2] = areas[j];
                if ((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1) <= (r1 + r2) * (r1 + r2)) {
                    if (ds.merge(i, j)) {
                        ans--;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
