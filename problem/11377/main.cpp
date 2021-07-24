#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, K;

struct Dinic {
    struct Edge {
        int v;
        int cap;
        int rev;

        Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> start;
    int source;
    int sink;

    Dinic(int N) : adj(N), level(N), start(N) {}

    void add_edge(int u, int v, int cap) {
        adj[u].emplace_back(v, cap, static_cast<int>(adj[v].size()));
        adj[v].emplace_back(u, 0, static_cast<int>(adj[u].size()) - 1);
    }

    bool bfs(void) {
        fill(level.begin(), level.end(), -1);
        queue<int> qu;
        level[source] = 0;
        qu.push(source);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for (auto [v, cap, _rev] : adj[u]) {
                if (level[v] == -1 && cap > 0) {
                    level[v] = level[u] + 1;
                    qu.push(v);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int u, int flow) {
        if (u == sink) {
            return flow;
        }
        for (int& st = start[u]; st < adj[u].size(); st++) {
            auto& [v, cap, rev] = adj[u][st];
            if (level[u] < level[v] && cap > 0) {
                int flowed = dfs(v, min(flow, cap));
                if (flowed > 0) {
                    cap -= flowed;
                    adj[v][rev].cap += flowed;
                    return flowed;
                }
            }
        }
        return 0;
    }

    int flow(int source, int sink) {
        this->source = source;
        this->sink = sink;
        int total = 0;
        while (bfs()) {
            fill(start.begin(), start.end(), 0);
            int flowed;
            while ((flowed = dfs(source, INF))) {
                total += flowed;
            }
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    Dinic dinic(N + M + 3);
    int source = 0;
    int sink = N + M + 1;
    int k_source = N + M + 2;
    dinic.add_edge(0, k_source, K);
    for (int u = 1; u <= N; u++) {
        dinic.add_edge(0, u, 1);
        dinic.add_edge(k_source, u, 1);
    }
    for (int v = 1; v <= M; v++) {
        dinic.add_edge(v + N, sink, 1);
    }
    for (int u = 1; u <= N; u++) {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            int v;
            cin >> v;
            v += N;
            dinic.add_edge(u, v, 1);
        }
    }
    cout << dinic.flow(source, sink) << "\n";
    return 0;
}
