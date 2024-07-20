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
    short N;
    cin >> N;
    FordFulkerson network(N * 2 + 2);
    int source = N * 2;
    int sink = N * 2 + 1;
    int sum_row = 0;
    for (int y = 0; y < N; y++) {
        short num;
        cin >> num;
        network.add_edge(source, y, num);
        for (int x = 0; x < N; x++) {
            network.add_edge(y, N + x, 1);
        }
        sum_row += num;
    }
    int sum_col = 0;
    for (int x = 0; x < N; x++) {
        short num;
        cin >> num;
        network.add_edge(N + x, sink, num);
        sum_col += num;
    }
    if (sum_row != sum_col) {
        cout << "-1\n";
        return 0;
    }
    int result = network.max_flow(source, sink);
    if (result != sum_row) {
        cout << "-1\n";
        return 0;
    }
    cout << "1\n";
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            bool found = false;
            for (auto& [v, _, flow, __] : network.graph[y]) {
                if (v == N + x) {
                    if (flow > 0) {
                        found = true;
                        cout << "1";
                    }
                }
            }
            if (!found) {
                cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}
