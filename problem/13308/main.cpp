#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<short> gas(N);
    for (short& num : gas) {
        cin >> num;
    }
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    vector<long long> dist(N * 2500, INF);
    priority_queue<pair<long long, int>> pq;
    dist[N * (gas[0] - 1)] = 0;
    pq.emplace(0, N * (gas[0] - 1));
    while (!pq.empty()) {
        auto [d, gu] = pq.top();
        d = -d;
        pq.pop();
        short g = gu / N + 1;
        short u = gu % N;
        if (u == N - 1) {
            cout << dist[gu] << "\n";
            return 0;
        }
        if (dist[gu] < d) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (gas[v] < g) {
                if (dist[N * (gas[v] - 1) + v] > d + w * g) {
                    dist[N * (gas[v] - 1) + v] = d + w * g;
                    pq.emplace(-(d + w * g), N * (gas[v] - 1) + v);
                }
            } else {
                if (dist[N * (g - 1) + v] > d + w * g) {
                    dist[N * (g - 1) + v] = d + w * g;
                    pq.emplace(-(d + w * g), N * (g - 1) + v);
                }
            }
        }
    }
    return 0;
}
