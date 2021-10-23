#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int V, E;
vector<vector<int>> graph;
vector<int> label;
int cnt = 1;
vector<bool> in_scc;
vector<vector<int>> scc;
stack<int> st;

int dfs(int u) {
    label[u] = cnt++;
    int res = label[u];
    st.emplace(u);
    for (int v : graph[u]) {
        if (in_scc[v]) {
            continue;
        }
        if (label[v] == 0) {
            int vtop = dfs(v);
            res = min(res, vtop);
        } else {
            res = min(res, label[v]);
        }
    }
    if (res == label[u]) {
        vector<int> component;
        while (true) {
            int v = st.top();
            st.pop();
            component.emplace_back(v);
            in_scc[v] = true;
            if (v == u) {
                break;
            }
        }
        sort(component.begin(), component.end());
        scc.emplace_back(component);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    graph.resize(V);
    label.resize(V);
    in_scc.resize(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].emplace_back(b - 1);
    }
    for (int u = 0; u < V; u++) {
        if (label[u] == 0) {
            dfs(u);
        }
    }
    cout << scc.size() << "\n";
    sort(scc.begin(), scc.end());
    for (vector<int>& component : scc) {
        for (int& u : component) {
            cout << u + 1 << " ";
        }
        cout << "-1\n";
    }
    return 0;
}
