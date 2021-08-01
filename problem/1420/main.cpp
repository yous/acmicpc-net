#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<string> city;

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
            while ((flowed = dfs(source, INF)) > 0) {
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
    city.resize(N);
    int source = -1;
    int sink = -1;
    for (int y = 0; y < N; y++) {
        cin >> city[y];
        if (source == -1 || sink == -1) {
            for (int x = 0; x < M; x++) {
                if (city[y][x] == 'K') {
                    source = y * M + x;
                } else if (city[y][x] == 'H') {
                    sink = y * M + x;
                }
            }
        }
    }
    bool can_block = true;
    int source_y = source / M;
    int source_x = source % M;
    for (int i = 0; i < 4; i++) {
        int ny = source_y + dy[i];
        int nx = source_x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
            continue;
        }
        if (ny * M + nx == sink) {
            can_block = false;
            break;
        }
    }
    if (!can_block) {
        cout << "-1\n";
        return 0;
    }
    Dinic dinic(N * M * 2);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            char ch = city[y][x];
            int pos = y * M + x;
            if (ch == '#') {
                continue;
            }
            if (ch == 'H') {
                sink = pos;
                continue;
            }
            dinic.add_edge(N * M + pos, pos, 1);
            if (ch == 'K') {
                source = pos;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || city[ny][nx] == '#') {
                    continue;
                }
                int new_pos = ny * M + nx;
                if (new_pos == sink) {
                    dinic.add_edge(pos, new_pos, 1);
                } else {
                    dinic.add_edge(pos, N * M + new_pos, 1);
                }
            }
        }
    }
    cout << dinic.flow(source, sink) << "\n";
    return 0;
}
