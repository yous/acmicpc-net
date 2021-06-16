#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1e9;
int T;
int N, M, K;
vector<tuple<int, int, int>> adj[100];
map<int, int> dist[100];

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
            dist[i].clear();
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
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(0, 0, 0);
        while (!pq.empty()) {
            int d, c, u;
            tie(d, c, u) = pq.top();
            d = -d;
            c = -c;
            pq.pop();
            auto it = dist[u].find(c);
            if (it == dist[u].end() || it->second < d) {
                continue;
            }
            for (auto& e : adj[u]) {
                int v, oc, od;
                tie(v, oc, od) = e;
                if (c + oc > M) {
                    continue;
                }
                auto it = dist[v].lower_bound(c + oc);
                if (it != dist[v].begin() && prev(it)->second <= d + od) {
                    if (it != dist[v].end() && it->first == c + oc && it->second >= d + od) {
                        dist[v].erase(it);
                    }
                    continue;
                }
                if (it != dist[v].end() && it->first == c + oc) {
                    if (d + od < it->second) {
                        it->second = d + od;
                        pq.emplace(-(d + od), -(c + oc), v);
                    }
                } else {
                    dist[v].emplace_hint(it, c + oc, d + od);
                    pq.emplace(-(d + od), -(c + oc), v);
                }
            }
        }
        int ans = INF;
        for (auto& kv : dist[N - 1]) {
            if (kv.second < ans) {
                ans = kv.second;
            }
        }
        if (ans == INF) {
            cout << "Poor KCM\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
