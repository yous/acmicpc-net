#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, K, Q;
vector<vector<pair<short, short>>> ADJ;
vector<vector<pair<short, short>>> ADJ_REV;
vector<short> hubs;
int dist[200][20001];
int dist_rev[200][20001];

void spfa(int s, int dist[], vector<vector<pair<short, short>>>& adj) {
    queue<short> qu;
    vector<bool> in_q(N + 1);
    dist[s] = 0;
    qu.emplace(s);
    in_q[s] = true;
    while (!qu.empty()) {
        short u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto& e : adj[u]) {
            short v = e.first,
                  d = e.second;
            int nd = dist[u] + d;
            if (dist[v] <= nd) {
                continue;
            }
            dist[v] = nd;
            if (!in_q[v]) {
                qu.emplace(v);
                in_q[v] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K >> Q;
    ADJ.resize(N + 1);
    ADJ_REV.resize(N + 1);
    for (int i = 0; i < K; i++) {
        fill(dist[i] + 1, dist[i] + N + 1, INF);
        fill(dist_rev[i] + 1, dist_rev[i] + N + 1, INF);
    }
    for (int i = 0; i < M; i++) {
        short u, v, d;
        cin >> u >> v >> d;
        ADJ[u].emplace_back(v, d);
        ADJ_REV[v].emplace_back(u, d);
    }
    for (int i = 0; i < K; i++) {
        short num;
        cin >> num;
        hubs.push_back(num);
    }
    for (int i = 0; i < K; i++) {
        spfa(hubs[i], dist[i], ADJ);
        spfa(hubs[i], dist_rev[i], ADJ_REV);
    }
    int valid_num = 0;
    long long sum = 0;
    for (int i = 0; i < Q; i++) {
        short a, b;
        cin >> a >> b;
        int _min = INF;
        for (int k = 0; k < K; k++) {
            if (dist_rev[k][a] == INF || dist[k][b] == INF) {
                continue;
            }
            _min = min(_min, dist_rev[k][a] + dist[k][b]);
        }
        if (_min != INF) {
            valid_num++;
            sum += _min;
        }
    }
    cout << valid_num << "\n";
    cout << sum << "\n";
    return 0;
}
