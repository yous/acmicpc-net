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
int cost[401][401];

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
        fill(cost[i] + 1, cost[i] + V + 1, INF);
        queue<int> qu;
        vector<bool> in_qu(V + 1, false);
        for (auto& e : adj[i]) {
            int v, w;
            tie(v, w) = e;
            cost[i][v] = w;
            qu.push(v);
            in_qu[v] = true;
        }
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            in_qu[u] = false;
            for (auto& e : adj[u]) {
                int v, w;
                tie(v, w) = e;
                if (cost[i][u] + w < cost[i][v]) {
                    cost[i][v] = cost[i][u] + w;
                    qu.push(v);
                    in_qu[v] = true;
                }
            }
        }
    }
    int _min = INF;
    for (int i = 1; i <= V; i++) {
        if (cost[i][i] < _min) {
            _min = cost[i][i];
        }
    }
    if (_min == INF) {
        cout << "-1\n";
    } else {
        cout << _min << "\n";
    }
    return 0;
}
