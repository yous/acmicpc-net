#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> adj(1000);
bool visited[1000];

void visit(int n) {
    visited[n] = true;
    for (auto other : adj[n]) {
        if (!visited[other]) {
            visit(other);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    int component = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visit(i);
            component++;
        }
    }
    cout << component << "\n";
    return 0;
}
