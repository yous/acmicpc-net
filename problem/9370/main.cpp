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
        int M;
        short t;
        cin >> N >> M >> t;
        vector<vector<pair<short, short>>> graph(N);
        short S, G, H;
        cin >> S >> G >> H;
        S--;
        G--;
        H--;
        for (int i = 0; i < M; i++) {
            short A, B, D;
            cin >> A >> B >> D;
            graph[A - 1].emplace_back(B - 1, D);
            graph[B - 1].emplace_back(A - 1, D);
        }
        vector<bool> targets(N);
        for (int i = 0; i < t; i++) {
            int num;
            cin >> num;
            targets[num - 1] = true;
        }
        vector<bool> in_q(N);
        queue<short> qu;
        vector<int> dist(N, INF);
        in_q[S] = true;
        qu.emplace(S);
        dist[S] = 0;
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
        short after = (dist[G] > dist[H] ? G : H);
        vector<bool> ans(N);
        ans[after] = true;
        in_q[after] = true;
        qu.emplace(after);
        while (!qu.empty()) {
            auto u = qu.front();
            qu.pop();
            in_q[u] = false;
            for (auto [v, w] : graph[u]) {
                if (dist[v] == dist[u] + w) {
                    ans[v] = true;
                    if (!in_q[v]) {
                        in_q[v] = true;
                        qu.emplace(v);
                    }
                }
            }
        }
        bool first = true;
        for (int i = 0; i < N; i++) {
            if (ans[i] && targets[i]) {
                if (first) {
                    first = false;
                } else {
                    cout << " ";
                }
                cout << i + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
