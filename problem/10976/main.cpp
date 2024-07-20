#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

struct FordFulkerson {
    int N;
    vector<vector<int>> cap, flow;

    FordFulkerson(int n) : N(n), cap(n, vector<int>(n)), flow(n, vector<int>(n)) {}

    void add_edge(int u, int v, int capacity) {
        cap[u][v] = capacity;
    }

    int max_flow(int source, int sink) {
        int total_flow = 0;
        while (true) {
            vector<int> from(N, -1);
            queue<int> qu;
            from[source] = source;
            qu.emplace(source);
            while (!qu.empty() && from[sink] == -1) {
                int u = qu.front();
                qu.pop();
                for (int v = 0; v < N; v++) {
                    if (from[v] == -1 && cap[u][v] - flow[u][v] > 0) {
                        from[v] = u;
                        qu.emplace(v);
                    }
                }
            }
            if (from[sink] == -1) {
                break;
            }
            int amount = INF;
            for (int u = sink; u != source; u = from[u]) {
                amount = min(amount, cap[from[u]][u] - flow[from[u]][u]);
            }
            for (int u = sink; u != source; u = from[u]) {
                flow[from[u]][u] += amount;
                flow[u][from[u]] -= amount;
            }
            total_flow += amount;
        }
        return total_flow;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T-- > 0) {
        short N, M;
        cin >> N >> M;
        FordFulkerson network(N);
        for (int i = 0; i < M; i++) {
            short u, v;
            cin >> u >> v;
            if (u == 1 || v == N) {
                network.add_edge(u - 1, v - 1, 1);
            } else {
                network.add_edge(u - 1, v - 1, 1000);
            }
        }
        cout << network.max_flow(0, N - 1) << "\n";
    }
    return 0;
}
