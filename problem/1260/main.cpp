#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<int> ADJ[1001];

void dfs(int u, vector<bool>& visited) {
    int cur = u;
    cout << cur;
    visited[cur] = true;
    for (auto v : ADJ[cur]) {
        if (!visited[v]) {
            visited[v] = true;
            cout << " ";
            dfs(v, visited);
        }
    }
}

void bfs(int u) {
    vector<bool> visited(N + 1);
    queue<int> qu;
    qu.push(u);
    cout << u;
    visited[u] = true;
    while (!qu.empty()) {
        int front = qu.front();
        qu.pop();
        for (auto v : ADJ[front]) {
            if (!visited[v]) {
                visited[v] = true;
                qu.push(v);
                cout << " " << v;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        ADJ[u].push_back(v);
        ADJ[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        sort(ADJ[i].begin(), ADJ[i].end());
    }
    vector<bool> visited(N + 1);
    dfs(V, visited);
    cout << "\n";
    bfs(V);
    return 0;
}
