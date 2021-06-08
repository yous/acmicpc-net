#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<pair<int, int>>> adj(1001);
vector<priority_queue<int>> dist(1001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1].push(0);
    while (!pq.empty()) {
        int cost, here;
        tie(cost, here) = pq.top();
        cost = -cost;
        pq.pop();
        if (dist[here].size() == K && dist[here].top() < cost) {
            continue;
        }
        for (auto& p : adj[here]) {
            int there, w;
            tie(there, w) = p;
            if (dist[there].size() < K || dist[there].top() > cost + w) {
                if (dist[there].size() == K) {
                    dist[there].pop();
                }
                dist[there].push(cost + w);
                pq.push({-(cost + w), there});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dist[i].size() < K) {
            cout << "-1\n";
        } else {
            cout << dist[i].top() << "\n";
        }
    }
    return 0;
}
