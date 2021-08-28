#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<double, double>> stars;

double dist(int i, int j) {
    double dx = stars[j].first - stars[i].first;
    double dy = stars[j].second - stars[i].second;
    return sqrt(dx * dx + dy * dy);
}

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
        return find(group[n]);
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
    cout << fixed;
    cout.precision(3);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        stars.emplace_back(x, y);
    }
    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            edges.emplace_back(dist(i, j), i, j);
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(N);
    double ans = 0;
    for (auto [d, u, v] : edges) {
        if (ds.merge(u, v)) {
            ans += d;
        }
    }
    cout << ans << "\n";
    return 0;
}
