#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
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
            group[gp] = gq;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int>> xyz[3];
    DisjointSet ds(N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xyz[0].emplace_back(x, i);
        xyz[1].emplace_back(y, i);
        xyz[2].emplace_back(z, i);
    }
    for (int i = 0; i < 3; i++) {
        sort(xyz[i].begin(), xyz[i].end());
    }
    vector<tuple<int, int, int>> xyz_diff[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N - 1; j++) {
            auto [x1, i1] = xyz[i][j];
            auto [x2, i2] = xyz[i][j + 1];
            xyz_diff[i].emplace_back(abs(x2 - x1), i1, i2);
        }
    }
    for (int i = 0; i < 3; i++) {
        sort(xyz_diff[i].begin(), xyz_diff[i].end());
    }
    int idx[3] = {0, 0, 0};
    int diffs[3] = {get<0>(xyz_diff[0][0]), get<0>(xyz_diff[1][0]), get<0>(xyz_diff[2][0])};
    long long ans = 0;
    while (true) {
        int i;
        if (idx[0] < N && diffs[0] <= diffs[1] && diffs[0] <= diffs[2]) {
            i = 0;
        } else if (idx[1] < N && diffs[1] <= diffs[0] && diffs[1] <= diffs[2]) {
            i = 1;
        } else if (idx[2] < N) {
            i = 2;
        } else {
            break;
        }
        auto [d, i1, i2] = xyz_diff[i][idx[i]];
        if (ds.merge(i1, i2)) {
            ans += d;
        }
        idx[i]++;
        diffs[i] = get<0>(xyz_diff[i][idx[i]]);
    }
    cout << ans << "\n";
    return 0;
}
