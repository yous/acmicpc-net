#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short INF = 30000;
short N, M, A, B, C;

bool solve(vector<vector<pair<short, short>>>& graph, short limit) {
    vector<short> dist(N, INF);
    vector<bool> in_q(N);
    queue<short> qu;
    dist[A] = 0;
    in_q[A] = true;
    qu.emplace(A);
    while (!qu.empty()) {
        short u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto [v, w] : graph[u]) {
            if (w > limit) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!in_q[v]) {
                    in_q[v] = true;
                    qu.emplace(v);
                }
            }
        }
    }
    return dist[B] <= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> A >> B >> C;
    A--;
    B--;
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    short lo = 1;
    short hi = 1000;
    while (lo <= hi) {
        short mid = (lo + hi) / 2;
        if (solve(graph, mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (lo > 1000) {
        cout << "-1\n";
    } else {
        cout << lo << "\n";
    }
    return 0;
}
