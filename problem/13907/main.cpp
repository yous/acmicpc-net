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
        short cnt = cnt_u / N;
        short u = cnt_u % N;
        if (cnt >= N - 1) {
            continue;
        }
        bool found = false;
        for (int i = 0; i <= cnt; i++) {
            if (dist[N * i + u] < d) {
                found = true;
                break;
            }
        }
        if (found) {
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
    int max_i = N - 1;
    for (int k = 0; k < K; k++) {
        tax += inc[k];
        ans = INF;
        for (int i = max_i; i >= 1; i--) {
            if (dist_d[i - 1] == INF) {
                continue;
            }
            if (ans > dist_d[i - 1] + tax * i) {
                ans = dist_d[i - 1] + tax * i;
                max_i = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
