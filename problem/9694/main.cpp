#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short INF = 30000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        short N, M;
        cin >> N >> M;
        vector<vector<pair<short, short>>> graph(M);
        for (int i = 0; i < N; i++) {
            short x, y, z;
            cin >> x >> y >> z;
            graph[x].emplace_back(y, z);
            graph[y].emplace_back(x, z);
        }
        vector<pair<short, short>> dist(M, {-1, INF});
        vector<bool> in_q(M);
        queue<short> qu;
        dist[0] = {-1, 0};
        in_q[0] = true;
        qu.emplace(0);
        while (!qu.empty()) {
            auto u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, c] : graph[u]) {
                if (dist[v].second > dist[u].second + c) {
                    dist[v] = {u, dist[u].second + c};
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                }
            }
        }
        if (dist[M - 1].first != -1) {
            short u = M - 1;
            vector<short> ans;
            ans.emplace_back(u);
            while (u != 0) {
                ans.emplace_back(dist[u].first);
                u = dist[u].first;
            }
            cout << "Case #" << t << ":";
            for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
                cout << " " << *it;
            }
            cout << "\n";
        } else {
            cout << "Case #" << t << ": -1\n";
        }
    }
    return 0;
}
