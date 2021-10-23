#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> label;
int cnt = 1;
vector<int> cut;

int dfs(int u) {
    label[u] = cnt++;
    int ans = label[u];
    bool find = false;
    for (int v : graph[u]) {
        if (label[v] == 0) {
            int vtop = dfs(v);
            ans = min(ans, vtop);
            if (label[u] <= vtop) {
                find = true;
            }
        } else {
            ans = min(ans, label[v]);
        }
    }
    if (find) {
        cut.emplace_back(u);
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
    for (int u = 0; u < V; u++) {
        if (label[u] == 0) {
            label[u] = cnt++;
            int nc = 0;
            for (int v : graph[u]) {
                if (label[v] == 0) {
                    nc++;
                    dfs(v);
                }
            }
            if (nc >= 2) {
                cut.emplace_back(u);
            }
        }
    }
    int sz = cut.size();
    cout << sz << "\n";
    sort(cut.begin(), cut.end());
    if (sz >= 1) {
        cout << cut[0] + 1;
        for (int i = 1; i < sz; i++) {
            cout << " " << cut[i] + 1;
        }
        cout << "\n";
    }
    return 0;
}
