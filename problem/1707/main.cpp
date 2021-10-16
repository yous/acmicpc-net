#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int K;
int V, E;
vector<vector<int>> ADJ;
vector<int> color;

bool dfs(int u, int c) {
    int nc = (c == 1 ? 2 : 1);
    for (int v : ADJ[u]) {
        if (color[v] == c) {
            return false;
        }
        if (color[v] == 0) {
            color[v] = nc;
            if (!dfs(v, color[v])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    while (K-- > 0) {
        cin >> V >> E;
        ADJ.clear();
        ADJ.resize(V);
        color.clear();
        color.resize(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            ADJ[u - 1].emplace_back(v - 1);
            ADJ[v - 1].emplace_back(u - 1);
        }
        bool can_make = true;
        for (int i = 0; i < V; i++) {
            if (color[i]) {
                continue;
            }
            color[i] = 1;
            if (!dfs(i, 1)) {
                can_make = false;
                cout << "NO\n";
                break;
            }
        }
        if (can_make) {
            cout << "YES\n";
        }
    }
    return 0;
}
