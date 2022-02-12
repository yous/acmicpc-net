#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        short N;
        int M;
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        vector<vector<pair<int, int>>> graph(N);
        short S, D;
        cin >> S >> D;
        for (int i = 0; i < M; i++) {
            short u, v;
            int p;
            cin >> u >> v >> p;
            graph[u].emplace_back(v, p);
        }
        vector<int> dist(N, INF);
        vector<vector<short>> prev_u(N);
        vector<bool> in_q(N);
        queue<short> qu;
        dist[S] = 0;
        in_q[S] = true;
        qu.emplace(S);
        while (!qu.empty()) {
            short u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    prev_u[v].clear();
                    prev_u[v].emplace_back(u);
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                } else if (dist[v] == dist[u] + w) {
                    prev_u[v].emplace_back(u);
                }
            }
        }
        vector<vector<bool>> blocked(N, vector<bool>(N));
        in_q[D] = true;
        qu.emplace(D);
        while (!qu.empty()) {
            short v = qu.front();
            qu.pop();
            in_q[v] = false;
            for (auto u : prev_u[v]) {
                blocked[u][v] = true;
                if (!in_q[u]) {
                    in_q[u] = true;
                    qu.emplace(u);
                }
            }
        }
        vector<int> ans(N, INF);
        ans[S] = 0;
        in_q[S] = true;
        qu.emplace(S);
        while (!qu.empty()) {
            short u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, w] : graph[u]) {
                if (blocked[u][v]) {
                    continue;
                }
                if (ans[v] > ans[u] + w) {
                    ans[v] = ans[u] + w;
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                }
            }
        }
        if (ans[D] == INF) {
            cout << "-1\n";
        } else {
            cout << ans[D] << "\n";
        }
    }
    return 0;
}
