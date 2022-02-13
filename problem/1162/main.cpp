#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> graph(N * (K + 1));
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        for (int j = 0; j <= K; j++) {
            graph[N * j + u - 1].emplace_back(N * j + v - 1, w);
            graph[N * j + v - 1].emplace_back(N * j + u - 1, w);
            if (j > 0) {
                graph[N * j + u - 1].emplace_back(N * (j - 1) + v - 1, 0);
                graph[N * j + v - 1].emplace_back(N * (j - 1) + u - 1, 0);
            }
        }
    }
    vector<long long> dist(N * (K + 1), INF);
    priority_queue<pair<long long, int>> pq;
    dist[N * K] = 0;
    pq.emplace(0, N * K);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        d = -d;
        pq.pop();
        if (dist[u] < d) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(-(d + w), v);
            }
        }
    }
    long long ans = INF;
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[N * i + N - 1]);
    }
    cout << ans << "\n";
    return 0;
}
