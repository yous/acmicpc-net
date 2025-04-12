#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K, W;
    cin >> N >> M >> K >> W;
    vector<string> names(N);
    unordered_map<string, vector<int>> name_map;
    for (int i = 0; i < W; i++) {
        int u;
        string s;
        cin >> u >> s;
        names[u - 1] = s;
        name_map[s].emplace_back(u - 1);
    }
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].emplace_back(b - 1);
        graph[b - 1].emplace_back(a - 1);
    }
    for (auto& [name, nodes] : name_map) {
        if (nodes.size() > 1) {
            vector<pair<int, int>> visited(N, {-1, -1});
            queue<int> qu;
            for (auto u : nodes) {
                visited[u] = {u, 0};
                qu.emplace(u);
            }
            int step = 1;
            while (!qu.empty()) {
                auto sz = qu.size();
                while (sz-- > 0) {
                    int u = qu.front();
                    qu.pop();
                    for (auto v : graph[u]) {
                        if (visited[v].first == -1) {
                            visited[v] = {visited[u].first, step};
                            qu.emplace(v);
                        } else if (visited[v].first != visited[u].first) {
                            if (visited[v].second + visited[u].second + 1 <= K) {
                                cout << "POWERFUL CODING JungHwan\n";
                                return 0;
                            }
                        }
                    }
                }
                if (step == K) {
                    break;
                }
                step++;
            }
        }
    }
    cout << "so sad\n";
    return 0;
}
