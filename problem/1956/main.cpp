#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 987654321;
int V, E;
vector<vector<pair<int, int>>> adj(401);
int dist[401][401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for (int i = 1; i <= V; i++) {
        fill(dist[i] + 1, dist[i] + V + 1, INF);
        priority_queue<pair<int, int>> pq;
        for (auto& e : adj[i]) {
            int v, w;
            tie(v, w) = e;
            dist[i][v] = w;
            pq.push({-w, v});
        }
        while (!pq.empty()) {
            int cost, here;
            tie(cost, here) = pq.top();
            cost = -cost;
            pq.pop();
            if (dist[i][here] < cost) {
                continue;
            }
            for (auto& e : adj[here]) {
                int v, w;
                tie(v, w) = e;
                if (dist[i][here] + w < dist[i][v]) {
                    dist[i][v] = dist[i][here] + w;
                    pq.push({-dist[i][v], v});
                }
            }
        }
    }
    int _min = INF;
    for (int i = 1; i <= V; i++) {
        if (dist[i][i] < _min) {
            _min = dist[i][i];
        }
    }
    if (_min == INF) {
        cout << "-1\n";
    } else {
        cout << _min << "\n";
    }
    return 0;
}
