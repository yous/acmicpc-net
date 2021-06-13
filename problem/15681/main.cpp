#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sub_count;

int gen_sub_count(int node) {
    int& ans = sub_count[node];
    ans = 1;
    for (auto n : adj[node]) {
        if (!visited[n]) {
            visited[n] = true;
            ans += gen_sub_count(n);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R >> Q;
    adj.resize(N);
    visited.resize(N);
    sub_count.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    visited[R - 1] = true;
    gen_sub_count(R - 1);
    for (int i = 0; i < Q; i++) {
        int u;
        cin >> u;
        cout << sub_count[u - 1] << "\n";
    }
    return 0;
}
