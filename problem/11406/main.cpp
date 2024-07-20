#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

struct FordFulkerson {
    struct Edge {
        int v, cap, flow, rev_idx;

        Edge(int v, int cap, int flow, int rev_idx) : v(v), cap(cap), flow(flow), rev_idx(rev_idx) {}
    };

    int N;
    vector<vector<Edge>> graph;

    FordFulkerson(int n) : N(n), graph(n) {}

    void add_edge(int u, int v, int capacity) {
        graph[u].emplace_back(v, capacity, 0, graph[v].size());
        graph[v].emplace_back(u, 0, 0, graph[u].size() - 1);
    }

    int max_flow(int source, int sink) {
        int total_flow = 0;
        while (true) {
            vector<pair<int, int>> from(N, {-1, -1});
            queue<int> qu;
            from[source] = {source, 0};
            qu.emplace(source);
            while (!qu.empty() && from[sink].first == -1) {
                int u = qu.front();
                qu.pop();
                int i = 0;
                for (auto& [v, cap, flow, _] : graph[u]) {
                    if (from[v].first == -1 && cap - flow > 0) {
                        from[v] = {u, i};
                        qu.emplace(v);
                    }
                    i++;
                }
            }
            if (from[sink].first == -1) {
                break;
            }
            int amount = INF;
            for (int u = sink; u != source; u = from[u].first) {
                auto [prev_u, i] = from[u];
                amount = min(amount, graph[prev_u][i].cap - graph[prev_u][i].flow);
            }
            for (int u = sink; u != source; u = from[u].first) {
                auto [prev_u, i] = from[u];
                graph[prev_u][i].flow += amount;
                graph[u][graph[prev_u][i].rev_idx].flow -= amount;
            }
            total_flow += amount;
        }
        return total_flow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    FordFulkerson network(N + M + 2);
    int source = N + M;
    int sink = N + M + 1;
    for (int i = 0; i < N; i++) {
        short A;
        cin >> A;
        network.add_edge(source, i, A);
    }
    for (int i = 0; i < M; i++) {
        short B;
        cin >> B;
        network.add_edge(N + i, sink, B);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            short C;
            cin >> C;
            network.add_edge(j, N + i, C);
        }
    }
    cout << network.max_flow(source, sink) << "\n";
    return 0;
}
