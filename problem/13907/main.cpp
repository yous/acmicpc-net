#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M, K;
    cin >> N >> M >> K;
    short S, D;
    cin >> S >> D;
    S--;
    D--;
    vector<vector<pair<short, short>>> graph(N);
    for (int i = 0; i < M; i++) {
        short u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }
    vector<short> inc(K);
    for (short& num : inc) {
        cin >> num;
    }
    vector<int> dist(N * N, INF);
    priority_queue<pair<int, int>> pq;
    dist[S] = 0;
    pq.emplace(0, S);
    while (!pq.empty()) {
        auto [d, cnt_u] = pq.top();
        d = -d;
        pq.pop();
        if (dist[cnt_u] < d) {
            continue;
        }
        short cnt = cnt_u / N;
        short u = cnt_u % N;
        if (cnt >= N - 1) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (dist[N * (cnt + 1) + v] > d + w) {
                dist[N * (cnt + 1) + v] = d + w;
                pq.emplace(-(d + w), N * (cnt + 1) + v);
            }
        }
    }
    vector<int> dist_d(N);
    for (int i = 1; i < N; i++) {
        dist_d[i - 1] = dist[N * i + D];
    }
    int ans = INF;
    for (int i = 0; i < N - 1; i++) {
        ans = min(ans, dist_d[i]);
    }
    cout << ans << "\n";
    int tax = 0;
    for (int i = 0; i < K; i++) {
        tax += inc[i];
        ans = INF;
        for (int j = 1; j < N; j++) {
            if (dist_d[j - 1] == INF) {
                continue;
            }
            ans = min(ans, dist_d[j - 1] + tax * j);
        }
        cout << ans << "\n";
    }
    return 0;
}
