#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(int cnt, vector<bool>& visited, vector<short>& ans, vector<vector<short>>& graph) {
    if (cnt == 5) {
        return true;
    }
    auto u = ans[cnt - 1];
    for (auto v : graph[u]) {
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        ans.emplace_back(v);
        bool ret = solve(cnt + 1, visited, ans, graph);
        ans.pop_back();
        visited[v] = false;
        if (ret) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<short>> graph(N);
    for (int i = 0; i < M; i++) {
        short A, B;
        cin >> A >> B;
        graph[A].emplace_back(B);
        graph[B].emplace_back(A);
    }
    vector<bool> visited(N);
    vector<short> ans;
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        ans.emplace_back(i);
        if (solve(1, visited, ans, graph)) {
            cout << "1\n";
            return 0;
        }
        ans.pop_back();
        visited[i] = false;
    }
    cout << "0\n";
    return 0;
}
