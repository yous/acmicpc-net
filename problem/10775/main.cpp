#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int G, P;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int N) : group(N) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            if (gp < gq) {
                group[gq] = gp;
            } else {
                group[gp] = gq;
            }
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> G >> P;
    DisjointSet ds(G + 1);
    int ans = 0;
    bool done = false;
    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;
        if (done) {
            continue;
        }
        int grp = ds.find(g);
        if (grp != 0 && ds.merge(grp, grp - 1)) {
            ans++;
        } else {
            done = true;
        }
    }
    cout << ans << "\n";
    return 0;
}
