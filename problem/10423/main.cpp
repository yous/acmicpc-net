#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    int M;
    short K;
    cin >> N >> M >> K;
    vector<bool> visited(N);
    for (int i = 0; i < K; i++) {
        short num;
        cin >> num;
        visited[num - 1] = true;
    }
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    priority_queue<pair<short, short>> pq;
    for (int u = 0; u < N; u++) {
        if (visited[u]) {
            for (auto [v, w] : graph[u]) {
                pq.emplace(-w, v);
            }
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        w = -w;
        pq.pop();
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        ans += w;
        for (auto [v2, w2] : graph[v]) {
            pq.emplace(-w2, v2);
        }
    }
    cout << ans << "\n";
    return 0;
}
