#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int u, vector<vector<int>>& graph, vector<int>& cache) {
    int& ans = cache[u];
    if (ans >= 0) {
        return ans;
    }
    ans = 1;
    int neighbors = graph[u].size();
    for (auto v : graph[u]) {
        if (graph[v].size() <= neighbors) {
            continue;
        }
        ans = max(ans, 1 + solve(v, graph, cache));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> cache(N, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i, graph, cache));
    }
    cout << ans << "\n";
    return 0;
}
