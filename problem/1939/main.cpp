#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].emplace_back(b - 1, c);
        adj[b - 1].emplace_back(a - 1, c);
    }
    int A, B;
    cin >> A >> B;
    dist.resize(N);
    priority_queue<pair<int, int>> qu;
    for (auto& p : adj[A - 1]) {
        int v = p.first,
            c = p.second;
        qu.emplace(c, v);
        dist[v] = c;
    }
    while (!qu.empty()) {
        auto& p = qu.top();
        int c = p.first,
            u = p.second;
        qu.pop();
        if (dist[u] > c) {
            continue;
        }
        if (u == B - 1) {
            continue;
        }
        for (auto& p : adj[u]) {
            int v = p.first,
                nc = min(c, p.second);
            if (nc > dist[v]) {
                qu.emplace(nc, v);
                dist[v] = nc;
            }
        }
    }
    cout << dist[B - 1] << "\n";
    return 0;
}
