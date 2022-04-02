#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool dfs(short u, short sz, vector<vector<short>>& graph, vector<bool>& visited) {
    bool is_minus = (u < 0);
    for (auto v : graph[abs(u)]) {
        if (is_minus) {
            if (visited[-v + sz]) {
                return false;
            }
            if (visited[v + sz]) {
                continue;
            }
            visited[v + sz] = true;
            if (!dfs(v, sz, graph, visited)) {
                return false;
            }
        } else {
            if (visited[v + sz]) {
                return false;
            }
            if (visited[-v + sz]) {
                continue;
            }
            visited[-v + sz] = true;
            if (!dfs(-v, sz, graph, visited)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    for (short t = 1; t <= T; t++) {
        short M;
        cin >> M;
        map<string, short> team;
        vector<pair<short, short>> edges;
        short idx = 1;
        for (int i = 0; i < M; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            short i1, i2;
            auto it = team.find(s1);
            if (it == team.end()) {
                team.emplace_hint(it, s1, idx);
                i1 = idx;
                idx++;
            } else {
                i1 = it->second;
            }
            it = team.find(s2);
            if (it == team.end()) {
                team.emplace_hint(it, s2, idx);
                i2 = idx;
                idx++;
            } else {
                i2 = it->second;
            }
            edges.emplace_back(i1, i2);
        }
        short sz = idx - 1;
        vector<vector<short>> graph(sz + 1);
        for (auto [i1, i2] : edges) {
            graph[i1].emplace_back(i2);
            graph[i2].emplace_back(i1);
        }
        vector<bool> visited(sz * 2 + 1);
        bool ans = true;
        for (short u = 1; u <= sz; u++) {
            if (visited[u + sz] || visited[-u + sz]) {
                continue;
            }
            visited[u + sz] = true;
            if (!dfs(u, sz, graph, visited)) {
                ans = false;
                break;
            }
        }
        cout << "Case #" << t << ": " << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
