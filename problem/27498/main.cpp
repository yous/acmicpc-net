#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    int N;
    vector<int> group;

    DisjointSet(int n) : N(n), group(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return (group[n] = find(g));
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
    short N;
    int M;
    cin >> N >> M;
    DisjointSet ds(N);
    vector<tuple<short, short, short>> edges;
    for (int i = 0; i < M; i++) {
        short a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d == 1) {
            ds.merge(a - 1, b - 1);
        } else {
            edges.emplace_back(-c, a - 1, b - 1);
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto& [c, a, b] : edges) {
        c = -c;
        if (!ds.merge(a, b)) {
            ans += c;
        }
    }
    cout << ans << "\n";
    return 0;
}
