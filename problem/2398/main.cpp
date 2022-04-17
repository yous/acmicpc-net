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
    vector<vector<pair<int, short>>> dist(3, vector<pair<int, short>>(N, {N * 100, -1}));
    for (int i = 0; i < 3; i++) {
        priority_queue<pair<int, short>> pq;
        dist[i][points[i]] = {0, -1};
        pq.emplace(0, points[i]);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            d = -d;
            pq.pop();
            if (dist[i][u].first < d) {
                continue;
            }
            for (auto [v, w] : graph[u]) {
                if (dist[i][v].first > d + w) {
                    dist[i][v] = {d + w, u};
                    pq.emplace(-(d + w), v);
                }
            }
        }
    }
    int min_dist = N * 100;
    int min_mid = -1;
    for (int mid = 0; mid < N; mid++) {
        int res = dist[0][mid].first + dist[1][mid].first + dist[2][mid].first;
        if (res < min_dist) {
            min_dist = res;
            min_mid = mid;
        }
    }
    vector<vector<short>> edges(3);
    for (int i = 0; i < 3; i++) {
        edges[i].emplace_back(min_mid);
        if (points[i] != min_mid) {
            short u = min_mid;
            while (u != points[i]) {
                edges[i].emplace_back(dist[i][u].second);
                u = dist[i][u].second;
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
