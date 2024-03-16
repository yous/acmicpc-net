#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void find_circular(vector<bool>& visited, vector<short>& selected, vector<vector<short>>& graph, vector<short>& dist) {
    auto u = selected.back();
    auto sz = selected.size();
    for (auto v : graph[u]) {
        if (visited[v]) {
            if (sz >= 2 && v != selected[sz - 2]) {
                for (auto it = selected.rbegin(); it != selected.rend(); ++it) {
                    dist[*it] = 0;
                    if (*it == v) {
                        break;
                    }
                }
            }
            continue;
        }
        visited[v] = true;
        selected.emplace_back(v);
        find_circular(visited, selected, graph, dist);
        selected.pop_back();
        visited[v] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> graph(N);
    for (int i = 0; i < N; i++) {
        short A, B;
        cin >> A >> B;
        graph[A - 1].emplace_back(B - 1);
        graph[B - 1].emplace_back(A - 1);
    }
    vector<bool> visited(N);
    vector<short> selected;
    visited[0] = true;
    selected.emplace_back(0);
    vector<short> dist(N, N + 1);
    find_circular(visited, selected, graph, dist);
    queue<short> qu;
    visited = vector<bool>(N);
    for (int i = 0; i < N; i++) {
        if (dist[i] == 0) {
            visited[i] = true;
            qu.emplace(i);
        }
    }
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        for (auto v : graph[u]) {
            if (visited[v] || dist[v] < dist[u] + 1) {
                continue;
            }
            visited[v] = true;
            dist[v] = dist[u] + 1;
            qu.emplace(v);
        }
    }
    cout << dist[0];
    for (int i = 1; i < N; i++) {
        cout << " " << dist[i];
    }
    cout << "\n";
    return 0;
}
