#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int V, E;
vector<tuple<int, int, int>> edges;

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
        p = find(p);
        q = find(q);
        if (p != q) {
            group[p] = q;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a - 1, b - 1);
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds = DisjointSet(V);
    int sum = 0;
    for (auto& edge : edges) {
        int c, a, b;
        tie(c, a, b) = edge;
        if (ds.merge(a, b)) {
            sum += c;
        }
    }
    cout << sum << "\n";
    return 0;
}
