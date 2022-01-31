#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].emplace_back(b - 1, c);
        graph[b - 1].emplace_back(a - 1, c);
    }
    int s, t;
    cin >> s >> t;
    queue<int> qu;
    vector<bool> in_q(N);
    vector<int> dist(N, INF);
    qu.emplace(s - 1);
    in_q[s - 1] = true;
    dist[s - 1] = 0;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!in_q[v]) {
                    in_q[v] = true;
                    qu.emplace(v);
                }
            }
        }
    }
    cout << dist[t - 1] << "\n";
    return 0;
}
