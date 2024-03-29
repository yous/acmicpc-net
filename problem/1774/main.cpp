#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
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

    int find(short n) {
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
    short N, M;
    cin >> N >> M;
    vector<pair<int, int>> gods(N);
    DisjointSet ds(N);
    for (auto& [x, y] : gods) {
        cin >> x >> y;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        ds.merge(u - 1, v - 1);
    }
    vector<tuple<long long, short, short>> distances(N * (N - 1) / 2);
    double ans = 0;
    int idx = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int dx = gods[j].first - gods[i].first;
            int dy = gods[j].second - gods[i].second;
            distances[idx] = {1LL * dx * dx + 1LL * dy * dy, i, j};
            idx++;
        }
    }
    sort(distances.begin(), distances.end());
    for (auto [dist, u, v] : distances) {
        if (ds.merge(u, v)) {
            ans += sqrt(dist);
        }
    }
    cout.precision(2);
    cout << fixed << ans << "\n";
    return 0;
}
