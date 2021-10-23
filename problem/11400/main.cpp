#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> label;
int cnt = 1;
vector<pair<int, int>> cut;

int dfs(int u, int s) {
    label[u] = cnt++;
    int ans = label[u];
    for (int v : graph[u]) {
        if (v == s) {
            continue;
        }
        if (label[v] == 0) {
            int vtop = dfs(v, u);
            ans = min(ans, vtop);
        } else {
            ans = min(ans, label[v]);
        }
    }
    if (ans > label[s]) {
        cut.emplace_back(minmax(u, s));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    graph.resize(V);
    label.resize(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].emplace_back(b - 1);
        graph[b - 1].emplace_back(a - 1);
    }
    label[0] = cnt++;
    for (int v : graph[0]) {
        if (label[v] == 0) {
            dfs(v, 0);
        }
    }
    cout << cut.size() << "\n";
    sort(cut.begin(), cut.end());
    for (auto& [a, b] : cut) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
    return 0;
}
