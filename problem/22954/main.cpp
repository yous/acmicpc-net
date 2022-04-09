#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, vector<int>& vertices, vector<int>& edges) {
    for (auto [v, e] : graph[u]) {
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        vertices.emplace_back(v);
        edges.emplace_back(e);
        dfs(v, graph, visited, vertices, edges);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].emplace_back(v - 1, i + 1);
        graph[v - 1].emplace_back(u - 1, i + 1);
    }
    vector<pair<vector<int>, vector<int>>> groups;
    vector<bool> visited(N);
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        vector<int> vertices;
        vector<int> edges;
        vertices.emplace_back(i);
        dfs(i, graph, visited, vertices, edges);
        groups.emplace_back(vertices, edges);
    }
    if (groups.size() > 2 || (groups.size() == 2 && groups[0].first.size() == groups[1].first.size()) || (groups.size() == 1 && groups[0].first.size() <= 2)) {
        cout << "-1\n";
    } else if (groups.size() == 1) {
        int sz = groups[0].first.size();
        cout << sz - 1 << " 1\n";
        cout << groups[0].first[0] + 1;
        for (int i = 1; i < sz - 1; i++) {
            cout << " " << groups[0].first[i] + 1;
        }
        cout << "\n";
        cout << groups[0].second[0];
        for (int i = 1; i < sz - 2; i++) {
            cout << " " << groups[0].second[i];
        }
        cout << "\n";
        cout << groups[0].first[sz - 1] + 1 << "\n";
        cout << "\n";
    } else {
        cout << groups[0].first.size() << " " << groups[1].first.size() << "\n";
        bool first = true;
        for (auto v : groups[0].first) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << v + 1;
        }
        cout << "\n";
        first = true;
        for (auto e : groups[0].second) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << e;
        }
        cout << "\n";
        first = true;
        for (auto v : groups[1].first) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << v + 1;
        }
        cout << "\n";
        first = true;
        for (auto e : groups[1].second) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << e;
        }
        cout << "\n";
    }
    return 0;
}
