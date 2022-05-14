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
            group[gp] = gq;
            cnt[gq] += cnt[gp];
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
    vector<int> queries(N);
    for (int& num : queries) {
        cin >> num;
        num--;
    }
    vector<bool> ans(N);
    vector<bool> added(N);
    DisjointSet ds(N);
    for (int i = N - 1; i >= 0; i--) {
        int u = queries[i];
        added[u] = true;
        for (auto v : graph[u]) {
            if (added[v]) {
                ds.merge(u, v);
            }
        }
        ans[i] = (ds.cnt[ds.find(u)] == N - i);
    }
    for (int i = 0; i < N; i++) {
        cout << (ans[i] ? "CONNECT\n" : "DISCONNECT\n");
    }
    cout << "DISCONNECT\n";
    return 0;
}
