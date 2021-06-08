#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<pair<int, int>>> adj(1001);
vector<int> dist(1001);
vector<int> nth(1001);

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
    while (!pq.empty()) {
        int cost, here;
        tie(cost, here) = pq.top();
        cost = -cost;
        pq.pop();
        if (nth[here] < K) {
            nth[here]++;
            dist[here] = cost;
            for (auto& p : adj[here]) {
                int there, w;
                tie(there, w) = p;
                if (nth[there] < K) {
                    pq.push({-(cost + w), there});
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (nth[i] < K) {
            cout << "-1\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}
