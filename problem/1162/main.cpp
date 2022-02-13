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
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    vector<long long> dist(N * (K + 1), INF);
    priority_queue<pair<long long, int>> pq;
    dist[N * K] = 0;
    pq.emplace(0, N * K);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        d = -d;
        pq.pop();
        int k = u / N;
        u %= N;
        if (dist[N * k + u] < d) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (dist[N * k + v] > d + w) {
                dist[N * k + v] = d + w;
                pq.emplace(-(d + w), N * k + v);
            }
            if (k > 0 && dist[N * (k - 1) + v] > d) {
                dist[N * (k - 1) + v] = d;
                pq.emplace(-d, N * (k - 1) + v);
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
