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
    int source, sink;
    cin >> source >> sink;
    source--;
    sink--;
    vector<int> costs(N);
    for (auto& num : costs) {
        cin >> num;
    }
    FordFulkerson network(N * 2);
    for (int i = 0; i < N; i++) {
        network.add_edge(i, i + N, costs[i]);
    }
    for (int i = 0; i < M; i++) {
        short A, B;
        cin >> A >> B;
        A--;
        B--;
        network.add_edge(A + N, B, INF);
        network.add_edge(B + N, A, INF);
    }
    network.max_flow(source, sink + N);
    vector<bool> visited(N * 2);
    queue<short> qu;
    visited[source] = true;
    qu.emplace(source);
    while (!qu.empty()) {
        short u = qu.front();
        qu.pop();
        for (auto& edge : network.graph[u]) {
            if (edge.cap - edge.flow > 0 && !visited[edge.v]) {
                visited[edge.v] = true;
                qu.emplace(edge.v);
            }
        }
    }
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (visited[i] && !visited[i + N]) {
            if (first) {
                first = false;
            } else {
                cout << " ";
            }
            cout << i + 1;
        }
    }
    cout << "\n";
    return 0;
}
