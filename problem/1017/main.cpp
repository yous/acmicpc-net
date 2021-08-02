#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;
vector<int> nums;
vector<bool> sieve(2001, true);

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

void gen_primes(vector<bool>& sieve) {
    int limit = sieve.size() - 1;
    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    gen_primes(sieve);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin() + 1, nums.end());
    int source = N * 2;
    int sink = source + 1;
    int start_idx = 1;
    bool first = true;
    while (true) {
        Dinic dinic(sink + 1);
        for (int j = start_idx; j < N; j++) {
            if (sieve[nums[0] + nums[j]]) {
                start_idx = j;
                break;
            }
        }
        if (!sieve[nums[0] + nums[start_idx]]) {
            break;
        }
        for (int i = 1; i < N; i++) {
            if (i == start_idx) {
                continue;
            }
            if (nums[i] % 2 == 1) {
                dinic.add_edge(source, i, 1);
            } else {
                dinic.add_edge(N + i, sink, 1);
            }
            for (int j = i + 1; j < N; j++) {
                if (j == start_idx) {
                    continue;
                }
                if (sieve[nums[i] + nums[j]]) {
                    if (nums[i] % 2 == 1) {
                        dinic.add_edge(i, N + j, 1);
                    } else {
                        dinic.add_edge(j, N + i, 1);
                    }
                }
            }
        }
        if (dinic.flow(source, sink) == (N - 2) / 2) {
            if (first) {
                first = false;
                cout << nums[start_idx];
            } else {
                cout << " " << nums[start_idx];
            }
        }
        start_idx++;
        if (start_idx >= N) {
            break;
        }
    }
    if (first) {
        cout << "-1\n";
    } else {
        cout << "\n";
    }
    return 0;
}
