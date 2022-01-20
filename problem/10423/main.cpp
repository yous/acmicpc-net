#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct DisjointSet {
    short N;
    vector<short> group;

    DisjointSet(short N) : N(N), group(N) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
        }
    }

    short find(short n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    bool merge(short p, short q) {
        short gp = find(p);
        short gq = find(q);
        if (gp != gq) {
            group[gq] = gp;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    int M;
    short K;
    cin >> N >> M >> K;
    vector<bool> station(N);
    for (int i = 0; i < K; i++) {
        short num;
        cin >> num;
        station[num - 1] = true;
    }
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    DisjointSet ds(N);
    priority_queue<tuple<short, short, short>> pq;
    for (int u = 0; u < N; u++) {
        if (station[u]) {
            for (auto [v, w] : graph[u]) {
                pq.emplace(-w, u, v);
            }
        }
    }
    int ans = 0;
    while (!pq.empty()) {
        auto [w, u, v] = pq.top();
        w = -w;
        pq.pop();
        if (station[ds.find(v)]) {
            continue;
        }
        ans += w;
        ds.merge(u, v);
        for (auto [v2, w2] : graph[v]) {
            pq.emplace(-w2, v, v2);
        }
    }
    cout << ans << "\n";
    return 0;
}
