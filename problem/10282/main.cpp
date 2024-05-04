#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = int(1e9);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short N;
        int D;
        short C;
        cin >> N >> D >> C;
        C--;
        vector<vector<pair<short, short>>> graph(N);
        for (int i = 0; i < D; i++) {
            short A, B, S;
            cin >> A >> B >> S;
            graph[B - 1].emplace_back(A - 1, S);
        }
        vector<bool> in_q(N);
        queue<short> qu;
        vector<int> dist(N, INF);
        in_q[C] = true;
        qu.emplace(C);
        dist[C] = 0;
        while (!qu.empty()) {
            auto u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                }
            }
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (dist[i] < INF) {
                cnt++;
                if (ans < dist[i]) {
                    ans = dist[i];
                }
            }
        }
        cout << cnt << " " << ans << "\n";
    }
    return 0;
}
