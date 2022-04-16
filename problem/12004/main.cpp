#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct DisjointSet {
    vector<short> group;
    vector<short> cnt;

    DisjointSet(short n) : group(n), cnt(n, 1) {
        iota(group.begin(), group.end(), 0);
    }

    short find(short n) {
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
    short N, M;
    cin >> N >> M;
    vector<vector<short>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1);
        graph[v - 1].emplace_back(u - 1);
    }
    vector<short> order(N);
    for (short& num : order) {
        cin >> num;
    }
    DisjointSet ds(N);
    vector<bool> closed(N, true);
    vector<bool> ans(N);
    for (int i = N - 1; i >= 0; i--) {
        short u = order[i] - 1;
        closed[u] = false;
        for (short v : graph[u]) {
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
