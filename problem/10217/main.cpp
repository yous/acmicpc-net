#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1e9;
int T;
int N, M, K;
vector<tuple<int, int, int>> adj[100];
int dist[100][10001];

struct DisjointSet {
    vector<int> group;

    DisjointSet(int n) : group(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    void merge(int p, int q) {
        p = find(p);
        q = find(q);
        if (p != q) {
            group[p] = q;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            adj[i].clear();
            fill(dist[i], dist[i] + M + 1, INF);
        }
        DisjointSet ds = DisjointSet(N);
        for (int i = 0; i < K; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            adj[u - 1].emplace_back(v - 1, c, d);
            ds.merge(u - 1, v - 1);
        }
        if (ds.find(0) != ds.find(N - 1)) {
            cout << "Poor KCM\n";
            continue;
        }
        for (int u = 0; u < N; u++) {
            vector<tuple<int, int, int>> tmp;
            sort(adj[u].begin(), adj[u].end());
            auto sz = adj[u].size();
            if (sz > 0) {
                auto [v, c, d] = adj[u][0];
                tmp.emplace_back(v, c, d);
                for (int i = 1; i < sz; i++) {
                    auto [ov, oc, od] = adj[u][i];
                    if (v == ov && c == oc) {
                        continue;
                    }
                    tmp.emplace_back(ov, oc, od);
                    v = ov;
                    c = oc;
                    d = od;
                }
            }
            swap(adj[u], tmp);
        }
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(0, 0, 0);
        int ans = INF;
        while (!pq.empty()) {
            int d, c, u;
            tie(d, c, u) = pq.top();
            d = -d;
            c = -c;
            pq.pop();
            if (u == N - 1) {
                ans = d;
                cout << ans << "\n";
                break;
            }
            int& udist = dist[u][c];
            if (udist < d) {
                continue;
            }
            for (auto& e : adj[u]) {
                int v, oc, od;
                tie(v, oc, od) = e;
                if (c + oc > M || dist[v][c + oc] <= d + od) {
                    continue;
                }
                for (int i = c + oc; i <= M; i++) {
                    if (dist[v][i] > d + od) {
                        dist[v][i] = d + od;
                    } else {
                        break;
                    }
                }
                pq.emplace(-(d + od), -(c + oc), v);
            }
        }
        if (ans == INF) {
            cout << "Poor KCM\n";
        }
    }
    return 0;
}
