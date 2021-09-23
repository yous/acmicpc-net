#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> ADJ;
vector<pair<int, int>> depths;
vector<int> leaves;
vector<int> parents;
vector<bool> early;

void dfs(int u, int s, int depth) {
    depths.emplace_back(-depth, u);
    bool has_child = false;
    for (auto v : ADJ[u]) {
        if (v == s) {
            continue;
        }
        has_child = true;
        parents[v] = u;
        dfs(v, u, depth + 1);
    }
    if (!has_child) {
        leaves.emplace_back(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N);
    parents.resize(N);
    early.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        ADJ[u - 1].emplace_back(v - 1);
        ADJ[v - 1].emplace_back(u - 1);
    }
    parents[0] = -1;
    dfs(0, -1, 0);
    int ans = 0;
    for (auto leaf : leaves) {
        if (!early[parents[leaf]]) {
            early[parents[leaf]] = true;
            ans++;
        }
    }
    sort(depths.begin(), depths.end());
    for (auto [depth, u] : depths) {
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
