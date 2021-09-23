#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> ADJ;
vector<int> nodes;
vector<bool> leaves;
vector<int> parents;
vector<bool> early;

void bfs(void) {
    queue<pair<int, int>> qu;
    parents[0] = -1;
    nodes.emplace_back(0);
    qu.emplace(0, -1);
    int depth = 1;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [u, s] = qu.front();
            qu.pop();
            bool has_child = false;
            for (auto v : ADJ[u]) {
                if (v == s) {
                    continue;
                }
                has_child = true;
                parents[v] = u;
                nodes.emplace_back(v);
                qu.emplace(v, u);
            }
            if (!has_child) {
                leaves[u] = true;
            }
        }
        depth++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N);
    leaves.resize(N);
    parents.resize(N);
    early.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        ADJ[u - 1].emplace_back(v - 1);
        ADJ[v - 1].emplace_back(u - 1);
    }
    bfs();
    int ans = 0;
    for (int u = 0; u < N; u++) {
        if (!leaves[u]) {
            continue;
        }
        if (!early[parents[u]]) {
            early[parents[u]] = true;
            ans++;
        }
    }
    for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
        int u = *it;
        if (early[u]) {
            continue;
        }
        int parent = parents[u];
        bool all_early = true;
        for (auto v : ADJ[u]) {
            if (v == parent) {
                continue;
            }
            if (!early[v]) {
                all_early = false;
                break;
            }
        }
        if (all_early) {
            if (parent != -1 && !early[parent]) {
                early[parent] = true;
                ans++;
            }
        } else {
            early[u] = true;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
