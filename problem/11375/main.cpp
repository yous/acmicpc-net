#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;

struct Dinic {
    struct Edge {
        short v;
        int cap;
        short rev;

        Edge(short v, int cap, short rev) : v(v), cap(cap), rev(rev) {}
    };

    vector<vector<Edge>> adj;
    vector<short> level;
    vector<short> start;
    short source;
    short sink;

    Dinic(int N) : adj(N), level(N), start(N) {}

    void add_edge(short u, short v, int cap) {
        adj[u].emplace_back(v, cap, static_cast<int>(adj[v].size()));
        adj[v].emplace_back(u, 0, static_cast<int>(adj[u].size()) - 1);
    }

    bool bfs(void) {
        fill(level.begin(), level.end(), -1);
        queue<short> qu;
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

    int dfs(short u, int flow) {
        if (u == sink) {
            return flow;
        }
        for (short& st = start[u]; st < adj[u].size(); st++) {
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

    int flow(short source, short sink) {
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
    cin >> N >> M;
    Dinic dinic(N + M + 2);
    short source = 0;
    short sink = N + M + 1;
    for (int u = 1; u <= N; u++) {
        dinic.add_edge(source, u, 1);
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
