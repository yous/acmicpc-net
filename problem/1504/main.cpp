#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 2e9;
int N, E;
vector<vector<pair<int, int>>> adj(801);
int V1, V2;
vector<int> dist1(801, INF);
vector<int> dist2(801, INF);

void dijkstra(int s, vector<int>& dist) {
    priority_queue<pair<int, int>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int cost, here;
        tie(cost, here) = pq.top();
        cost = -cost;
        pq.pop();
        if (dist[here] < cost) {
            continue;
        }
        for (auto& e : adj[here]) {
            int v, w;
            tie(v, w) = e;
            int new_cost = dist[here] + w;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({-new_cost, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> V1 >> V2;
    dijkstra(V1, dist1);
    dijkstra(V2, dist2);
    int ans = INF;
    if (dist1[V2] != INF) {
        if (dist1[1] != INF && dist2[N] != INF) {
            ans = min(ans, dist1[1] + dist1[V2] + dist2[N]);
        }
        if (dist2[1] != INF && dist1[N] != INF) {
            ans = min(ans, dist2[1] + dist2[V1] + dist1[N]);
        }
    }
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
