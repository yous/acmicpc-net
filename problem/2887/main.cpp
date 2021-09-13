#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> group;
    vector<int> cnt;

    DisjointSet(int n) : group(n), cnt(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
            cnt[i] = 1;
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
            if (cnt[gp] < cnt[gq]) {
                group[gp] = gq;
                cnt[gq] += cnt[gp];
            } else {
                group[gq] = gp;
                cnt[gp] += cnt[gq];
            }
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
    for (int i = 0; i < 3; i++) {
        xyz[i].resize(N);
    }
    DisjointSet ds(N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xyz[0][i] = {x, i};
        xyz[1][i] = {y, i};
        xyz[2][i] = {z, i};
    }
    for (int i = 0; i < 3; i++) {
        sort(xyz[i].begin(), xyz[i].end());
    }
    vector<tuple<int, int, int>> xyz_diff[3];
    for (int i = 0; i < 3; i++) {
        xyz_diff[i].resize(N - 1);
        for (int j = 0; j < N - 1; j++) {
            auto [x1, i1] = xyz[i][j];
            auto [x2, i2] = xyz[i][j + 1];
            xyz_diff[i][j] = {x2 - x1, i1, i2};
        }
        sort(xyz_diff[i].begin(), xyz_diff[i].end());
    }
    int idx[3] = {0, 0, 0};
    int diffs[3] = {get<0>(xyz_diff[0][0]), get<0>(xyz_diff[1][0]), get<0>(xyz_diff[2][0])};
    long long ans = 0;
    int cnt = 0;
    while (true) {
        int i;
        if (diffs[0] <= diffs[1] && diffs[0] <= diffs[2]) {
            i = 0;
        } else if (diffs[1] <= diffs[0] && diffs[1] <= diffs[2]) {
            i = 1;
        } else {
            i = 2;
        }
        auto [d, i1, i2] = xyz_diff[i][idx[i]];
        if (ds.merge(i1, i2)) {
            ans += d;
            cnt++;
            if (cnt == N - 1) {
                break;
            }
        }
        idx[i]++;
        if (idx[i] < N) {
            diffs[i] = get<0>(xyz_diff[i][idx[i]]);
        } else {
            diffs[i] = static_cast<int>(2e9) + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
