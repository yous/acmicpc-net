#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, short>>> graph(V);
    int K;
    cin >> K;
    K--;
    for (int i = 0; i < E; i++) {
        int u, v;
        short w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
    }
    vector<int> dist(V, INF);
    priority_queue<pair<int, int>> pq;
    dist[K] = 0;
    pq.emplace(0, K);
    while (!pq.empty()) {
        auto [cost, here] = pq.top();
        cost = -cost;
        pq.pop();
        if (dist[here] < cost) {
            continue;
        }
        for (auto [v, w] : graph[here]) {
            if (dist[v] > cost + w) {
                dist[v] = cost + w;
                pq.emplace(-(cost + w), v);
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}
