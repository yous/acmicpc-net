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

    void max_flow(int source, int sink, vector<pair<int, short>>& B, pair<int, int> groups) {
        auto [src_cnt, dst_cnt] = groups;
        for (auto [_, idx] : B) {
            vector<pair<int, int>> from(N, {-1, -1});
            queue<int> qu;
            from[source] = {source, 0};
            from[idx] = {source, idx};
            qu.emplace(idx);
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
                continue;
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
        }
        vector<vector<short>> group(dst_cnt);
        for (int u = 0; u < src_cnt; u++) {
            for (auto& [v, _, flow, __] : graph[u]) {
                if (flow > 0) {
                    group[v - src_cnt].emplace_back(u + 1);
                }
            }
        }
        for (int k = 0; k < dst_cnt; k++) {
            cout << group[k].size();
            for (auto& num : group[k]) {
                cout << " " << num;
            }
            cout << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, K, X;
    cin >> N >> K >> X;
    vector<vector<short>> A(N);
    for (int i = 0; i < N; i++) {
        short C;
        cin >> C;
        A[i].resize(C);
        for (auto& num : A[i]) {
            cin >> num;
            num--;
        }
    }
    vector<pair<int, short>> B(N);
    int i = 0;
    for (auto& [num, idx] : B) {
        cin >> num;
        num = -num;
        idx = i;
        i++;
    }
    sort(B.begin(), B.end());
    FordFulkerson network(N + K + 2);
    int source = N + K;
    int sink = N + K + 1;
    for (auto [_, idx] : B) {
        network.add_edge(source, idx, 1);
        for (auto group : A[idx]) {
            network.add_edge(idx, N + group, 1);
        }
    }
    for (int i = 0; i < K; i++) {
        network.add_edge(N + i, sink, X);
    }
    network.max_flow(source, sink, B, {N, K});
    return 0;
}
