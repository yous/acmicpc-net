#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<short> group;

    DisjointSet(int n) : N(n), group(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (n == g) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
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
    short N;
    cin >> N;
    vector<pair<short, short>> homeworks(N);
    for (auto& [w, d] : homeworks) {
        cin >> d >> w;
    }
    sort(homeworks.begin(), homeworks.end(), greater<pair<short, short>>());
    DisjointSet ds(1001);
    int ans = 0;
    for (auto [w, d] : homeworks) {
        int g = ds.find(d);
        if (g > 0) {
            ds.merge(g - 1, g);
            ans += w;
        }
    }
    cout << ans << "\n";
    return 0;
}
