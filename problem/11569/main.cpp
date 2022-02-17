#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int N, M, S, D;
        cin >> N >> M >> S >> D;
        S--;
        D--;
        vector<vector<pair<int, int>>> graph(N);
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u - 1].emplace_back(v - 1, w);
            graph[v - 1].emplace_back(u - 1, w);
        }
        for (int i = 0; i < N; i++) {
            sort(graph[i].begin(), graph[i].end());
        }
        vector<short> period(N);
        for (short& num : period) {
            cin >> num;
        }
        vector<long long> dist(N, INF);
        priority_queue<pair<long long, int>> pq;
        dist[S] = 0;
        pq.emplace(0, S);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            d = -d;
            pq.pop();
            if (dist[u] < d) {
                continue;
            }
            for (auto [v, w] : graph[u]) {
                if (v == D) {
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        pq.emplace(-(d + w), v);
                    }
                    continue;
                }
                if (dist[v] <= d + w) {
                    continue;
                }
                int sz = graph[v].size();
                int idx = distance(graph[v].begin(), lower_bound(graph[v].begin(), graph[v].end(), make_pair(u, 0)));
                short p = period[v];
                int cur_time = (d + w) % (sz * p);
                int stay;
                if (cur_time / p == idx) {
                    stay = 0;
                } else {
                    stay = 0;
                    if (cur_time % p > 0) {
                        stay += p - cur_time % p;
                        cur_time += stay;
                    }
                    stay += ((idx + sz - cur_time / p) % sz) * p;
                }
                if (dist[v] > d + w + stay) {
                    dist[v] = d + w + stay;
                    pq.emplace(-(d + w + stay), v);
                }
            }
        }
        if (dist[D] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[D] << "\n";
        }
    }
    return 0;
}
