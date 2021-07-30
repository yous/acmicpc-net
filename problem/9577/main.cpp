#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int T;
int N, M;

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
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M;
        int source = N + M + 100;
        int sink = N + M + 100 + 1;
        Dinic dinic(N + M + 100 + 2);
        for (int i = 0; i < 100; i++) {
            dinic.add_edge(source, N + M + i, 1);
        }
        for (int i = 0; i < M; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            for (int t = t1; t < t2; t++) {
                dinic.add_edge(N + M + t, N + i, 1);
            }
            int cnt;
            cin >> cnt;
            for (int j = 0; j < cnt; j++) {
                int q;
                cin >> q;
                dinic.add_edge(N + i, q - 1, 1);
            }
        }
        for (int i = 0; i < N; i++) {
            dinic.add_edge(i, sink, 1);
        }
        int flowed = dinic.flow(source, sink);
        if (flowed < N) {
            cout << "-1\n";
        } else {
            for (int i = 99; i >= 0; i--) {
                if (dinic.adj[source][i].cap == 0) {
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
