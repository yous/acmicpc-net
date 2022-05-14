#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, vector<vector<int>>& graph, vector<int>& fans) {
    auto it = lower_bound(fans.begin(), fans.end(), u);
    if (it != fans.end() && *it == u) {
        return true;
    }
    if (graph[u].empty()) {
        return false;
    }
    for (auto v : graph[u]) {
        if (!dfs(v, graph, fans)) {
            return false;
        }
    }
    return true;
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
        graph[u - 1].emplace_back(v - 1);
    }
    int S;
    cin >> S;
    vector<int> fans(S);
    for (int& num : fans) {
        cin >> num;
        num--;
    }
    sort(fans.begin(), fans.end());
    if (dfs(0, graph, fans)) {
        cout << "Yes\n";
    } else {
        cout << "yes\n";
    }
    return 0;
}
