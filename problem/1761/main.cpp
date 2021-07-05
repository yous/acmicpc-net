#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, short>>> ADJ;
vector<vector<int>> sparse_table;
vector<int> depths;
vector<int> dist;

int query(int u, int v) {
    int u_depth = depths[u];
    int v_depth = depths[v];
    if (u_depth != v_depth) {
        if (u_depth > v_depth) {
            swap(u, v);
            swap(u_depth, v_depth);
        }
        int diff = v_depth - u_depth;
        while (diff > 0) {
            int power = 31 - __builtin_clz(diff);
            v = sparse_table[power][v];
            diff -= (1 << power);
        }
    }
    if (u == v) {
        return u;
    }
    for (int p = 15; p >= 0; p--) {
        int u_parent = sparse_table[p][u];
        int v_parent = sparse_table[p][v];
        if (u_parent == 0 || u_parent == v_parent) {
            continue;
        }
        u = u_parent;
        v = v_parent;
    }
    return sparse_table[0][u];
}

int distance(int u, int v) {
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N + 1);
    depths.resize(N + 1);
    dist.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        short d;
        cin >> u >> v >> d;
        ADJ[u].emplace_back(v, d);
        ADJ[v].emplace_back(u, d);
    }
    sparse_table.resize(16);
    queue<pair<int, int>> qu;
    sparse_table[0].resize(N + 1);
    sparse_table[0][1] = 0;
    qu.emplace(1, 0);
    depths[1] = 0;
    dist[1] = 0;
    while (!qu.empty()) {
        auto& p = qu.front();
        int u = p.first,
            e = p.second;
        qu.pop();
        for (auto& p : ADJ[u]) {
            int v = p.first;
            short d = p.second;
            if (v != e) {
                sparse_table[0][v] = u;
                qu.emplace(v, u);
                depths[v] = depths[u] + 1;
                dist[v] = dist[u] + d;
            }
        }
    }
    for (int p = 1; p <= 15; p++) {
        sparse_table[p].resize(N + 1);
        for (int i = 1; i <= N; i++) {
            int parent = sparse_table[p - 1][i];
            if (parent == 0) {
                sparse_table[p][i] = 0;
            } else {
                sparse_table[p][i] = sparse_table[p - 1][parent];
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << distance(u, v) << "\n";
    }
    return 0;
}
