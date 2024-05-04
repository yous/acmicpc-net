#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = int(1e9);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        short C;
        cin >> A >> B >> C;
        graph[A - 1].emplace_back(B - 1, C);
        graph[B - 1].emplace_back(A - 1, C);
    }
    vector<int> dist(N, INF);
    dist[0] = 0;
    vector<bool> in_q(N);
    queue<int> qu;
    in_q[0] = true;
    qu.emplace(0);
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                if (!in_q[v]) {
                    in_q[v] = true;
                    qu.emplace(v);
                }
            }
        }
    }
    cout << dist[N - 1] << "\n";
    return 0;
}
