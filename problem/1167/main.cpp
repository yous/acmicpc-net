#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<pair<int, int>>> ADJ;
vector<int> dist;

void dfs(int u, int s, vector<int>& dist) {
    for (auto [v, w] : ADJ[u]) {
        if (dist[v] != -1) {
            continue;
        }
        if (s == -1 || v != s) {
            dist[v] = dist[u] + w;
            dfs(v, u, dist);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    ADJ.resize(V);
    dist.resize(V, -1);
    for (int i = 0; i < V; i++) {
        int u, v;
        cin >> u;
        while (cin >> v) {
            if (v == -1) {
                break;
            }
            int w;
            cin >> w;
            ADJ[u - 1].emplace_back(v - 1, w);
        }
    }
    dist[0] = 0;
    dfs(0, -1, dist);
    int far = 0;
    int max_d = 0;
    for (int i = 0; i < V; i++) {
        if (max_d < dist[i]) {
            far = i;
            max_d = dist[i];
        }
    }
    fill(dist.begin(), dist.end(), -1);
    dist[far] = 0;
    dfs(far, -1, dist);
    int far2 = 0;
    max_d = 0;
    for (int i = 0; i < V; i++) {
        if (max_d < dist[i]) {
            far2 = i;
            max_d = dist[i];
        }
    }
    cout << dist[far2] << "\n";
    return 0;
}
