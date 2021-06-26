#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> adj;
int dist[200][200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    adj.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int S, E, L;
        cin >> S >> E >> L;
        adj[S - 1].emplace_back(E - 1, L);
        adj[E - 1].emplace_back(S - 1, L);
        if (S != E) {
            int& d = dist[S - 1][E - 1];
            if (d > 0) {
                d = min(d, L);
            }
            dist[E - 1][S - 1] = d;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int _min = INF;
    for (int i = 0; i < N; i++) {
        int t = 0;
        for (int u = 0; u < N; u++) {
            int dist_u = dist[i][u];
            for (auto& p : adj[u]) {
                int v = p.first,
                    c = p.second;
                if (u == v) {
                    t = max(t, dist_u * 10 + c * 10 / 2);
                } else {
                    int dist_v = dist[i][v];
                    if (dist_u + c <= dist[i][v]) {
                        t = max(t, (dist_u + c) * 10);
                    } else {
                        t = max(t, (dist_u + (dist_v - dist_u)) * 10 + (c - (dist_v - dist_u)) * 10 / 2);
                    }
                }
            }
        }
        _min = min(_min, t);
    }
    cout.precision(1);
    cout << fixed << _min / 10.0 << "\n";
    return 0;
}
