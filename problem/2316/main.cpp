#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, P;

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
    cin >> N >> P;
    Dinic dinic(N * 2);
    int source = 0;
    int sink = 1;
    for (int i = 2; i < N; i++) {
        dinic.add_edge(N + i, i, 1);
    }
    for (int i = 0; i < P; i++) {
        int a, b;
        cin >> a >> b;
        if (b <= 2) {
            dinic.add_edge(a - 1, b - 1, 1);
        } else {
            dinic.add_edge(a - 1, N + b - 1, 1);
        }
        if (a <= 2) {
            dinic.add_edge(b - 1, a - 1, 1);
        } else {
            dinic.add_edge(b - 1, N + a - 1, 1);
        }
    }
    cout << dinic.flow(source, sink) << "\n";
    return 0;
}
