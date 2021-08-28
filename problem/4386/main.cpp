#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
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
    priority_queue<tuple<double, int, int>> pq;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pq.emplace(-dist(i, j), i, j);
        }
    }
    DisjointSet ds(N);
    double ans = 0;
    while (!pq.empty()) {
        auto [d, i, j] = pq.top();
        d = -d;
        pq.pop();
        if (ds.merge(i, j)) {
            ans += d;
        }
    }
    cout << ans << "\n";
    return 0;
}
