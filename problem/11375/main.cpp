#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<short>> ADJ;
vector<bool> visited;
vector<short> matched;

bool dfs(int u) {
    visited[u] = true;
    for (int v : ADJ[u]) {
        if (matched[v] == 0 || (!visited[matched[v]] && dfs(matched[v]))) {
            matched[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    ADJ.resize(N + 1);
    visited.resize(N + 1);
    matched.resize(M + 1);
    for (int u = 1; u <= N; u++) {
        int cnt;
        cin >> cnt;
        for (int i = 0; i < cnt; i++) {
            int v;
            cin >> v;
            ADJ[u].push_back(v);
        }
    }
    int ans = 0;
    for (int u = 1; u <= N; u++) {
        fill(visited.begin(), visited.end(), false);
        if (dfs(u)) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
