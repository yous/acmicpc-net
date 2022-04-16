#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<int> group;
    vector<int> cnt;

    DisjointSet(int n) : group(n), cnt(n, 1) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        int g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gq] = gp;
            cnt[gp] += cnt[gq];
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    vector<int> order(N);
    for (int& num : order) {
        cin >> num;
    }
    DisjointSet ds(N);
    vector<bool> closed(N, true);
    vector<bool> ans(N);
    ans[N - 1] = true;
    closed[order[N - 1] - 1] = false;
    for (int i = N - 2; i >= 0; i--) {
        int u = order[i] - 1;
        closed[u] = false;
        for (int v : graph[u]) {
            if (!closed[v]) {
                ds.merge(u, v);
            }
        }
        ans[i] = (ds.cnt[u] == N - i);
    }
    for (int i = 0; i < N; i++) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
    return 0;
}
