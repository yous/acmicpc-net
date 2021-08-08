#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int V;
vector<vector<pair<int, int>>> ADJ;

void dfs(int u, int s, vector<int>& dist) {
    for (auto [v, w] : ADJ[u]) {
        if (s == -1 || v != s) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                dfs(v, u, dist);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    ADJ.resize(V);
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
    vector<int> dist(V, -1);
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
