#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int S, E;
    cin >> S >> E;
    S--;
    E--;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].emplace_back(y - 1);
        graph[y - 1].emplace_back(x - 1);
    }
    vector<bool> visited(N);
    queue<int> qu;
    visited[S] = true;
    qu.emplace(S);
    int time = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int u = qu.front();
            qu.pop();
            if (u == E) {
                cout << time << "\n";
                return 0;
            }
            if (u > 0 && !visited[u - 1]) {
                visited[u - 1] = true;
                qu.emplace(u - 1);
            }
            if (u < N - 1 && !visited[u + 1]) {
                visited[u + 1] = true;
                qu.emplace(u + 1);
            }
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    qu.emplace(v);
                }
            }
        }
        time++;
    }
    return 0;
}
