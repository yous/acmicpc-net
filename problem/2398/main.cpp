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
    cin >> N >> M;
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    short points[3];
    cin >> points[0] >> points[1] >> points[2];
    points[0]--;
    points[1]--;
    points[2]--;
    int min_dist = N * 100;
    vector<vector<short>> edges(3);
    for (short mid = 0; mid < N; mid++) {
        vector<pair<int, short>> dist(N, {N * 100, -1});
        priority_queue<pair<int, short>> pq;
        dist[mid] = {0, -1};
        pq.emplace(0, mid);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            d = -d;
            pq.pop();
            if (dist[u].first < d) {
                continue;
            }
            for (auto [v, w] : graph[u]) {
                if (dist[v].first > d + w) {
                    dist[v] = {d + w, u};
                    pq.emplace(-(d + w), v);
                }
            }
        }
        int res = dist[points[0]].first + dist[points[1]].first + dist[points[2]].first;
        if (res < min_dist) {
            min_dist = res;
            for (int i = 0; i < 3; i++) {
                edges[i].clear();
                edges[i].emplace_back(points[i]);
                if (points[i] != mid) {
                    short u = points[i];
                    while (u != mid) {
                        edges[i].emplace_back(dist[u].second);
                        u = dist[u].second;
                    }
                }
            }
        }
    }
    cout << min_dist << " " << (edges[0].size() + edges[1].size() + edges[2].size() - 3) << "\n";
    for (int i = 0; i < 3; i++) {
        short u = edges[i][0];
        int sz = edges[i].size();
        for (int j = 1; j < sz; j++) {
            short v = edges[i][j];
            cout << u + 1 << " " << v + 1 << "\n";
            u = v;
        }
    }
    return 0;
}
