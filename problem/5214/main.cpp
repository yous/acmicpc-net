#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    short K, M;
    cin >> N >> K >> M;
    vector<vector<int>> graph(N + M);
    for (int tube = 0; tube < M; tube++) {
        for (int i = 0; i < K; i++) {
            int num;
            cin >> num;
            num--;
            graph[num].emplace_back(N + tube);
            graph[N + tube].emplace_back(num);
        }
    }
    vector<bool> visited(N + M);
    queue<int> qu;
    visited[0] = true;
    qu.emplace(0);
    int step = 0;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto u = qu.front();
            qu.pop();
            if (u == N - 1) {
                cout << step / 2 + 1 << "\n";
                return 0;
            }
            for (auto v : graph[u]) {
                if (visited[v]) {
                    continue;
                }
                visited[v] = true;
                qu.emplace(v);
            }
        }
        step++;
    }
    cout << "-1\n";
    return 0;
}
