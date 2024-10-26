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
    short T;
    cin >> T;
    while (T-- > 0) {
        short N;
        int E;
        short A, B;
        cin >> N >> E >> A >> B;
        vector<vector<pair<short, short>>> graph(N);
        short source = N;
        short sink = N + 1;
        FordFulkerson network(N + 2);
        network.add_edge(source, A, INF);
        for (int i = 0; i < E; i++) {
            short U, V, W;
            cin >> U >> V >> W;
            graph[U].emplace_back(V, W);
            network.add_edge(U, V, W);
        }
        network.add_edge(B, sink, INF);
        vector<short> dist(N);
        vector<bool> in_q(N);
        queue<short> qu;
        dist[A] = 1000;
        in_q[A] = true;
        qu.emplace(A);
        while (!qu.empty()) {
            auto u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, w] : graph[u]) {
                short prev_dist = min(dist[u], w);
                if (dist[v] < prev_dist) {
                    dist[v] = prev_dist;
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                }
            }
        }
        int one_way = dist[B];
        int all_way = network.max_flow(source, sink);
        cout.precision(3);
        cout << fixed << double(all_way) / one_way << "\n";
    }
    return 0;
}
