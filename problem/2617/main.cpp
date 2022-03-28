#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

short N;

void dfs(int u, vector<vector<short>>& graph, vector<bool>& visited) {
    for (auto v : graph[u]) {
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        dfs(v, graph, visited);
    }
}

short solve(int u, vector<vector<short>>& graph) {
    vector<bool> visited(N);
    visited[u] = true;
    dfs(u, graph, visited);
    short cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == u) {
            continue;
        }
        if (visited[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short M;
    cin >> N >> M;
    vector<vector<short>> lighter_graph(N);
    vector<vector<short>> heavier_graph(N);
    for (int i = 0; i < M; i++) {
        short b, a;
        cin >> b >> a;
        lighter_graph[b - 1].emplace_back(a - 1);
        heavier_graph[a - 1].emplace_back(b - 1);
    }
    short ans = 0;
    for (int u = 0; u < N; u++) {
        if (solve(u, lighter_graph) > N / 2) {
            ans++;
            continue;
        }
        if (solve(u, heavier_graph) > N / 2) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
