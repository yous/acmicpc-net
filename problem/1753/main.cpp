#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
int V, E;
int K;
vector<vector<pair<int, int>>> adj(20001);
vector<int> dist(20001);

void dijkstra(int n) {
    fill(dist.begin() + 1, dist.begin() + V + 1, INF);
    dist[n] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, n});
    while (!pq.empty()) {
        int cost, here;
        tie(cost, here) = pq.top();
        cost = -cost;
        pq.pop();
        if (dist[here] < cost) {
            continue;
        }
        for (auto& p : adj[here]) {
            int v, w;
            tie(v, w) = p;
            if (cost + w < dist[v]) {
                dist[v] = cost + w;
                pq.push({-(cost + w), v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}
