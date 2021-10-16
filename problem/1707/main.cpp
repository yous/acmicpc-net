#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int K;
int V, E;
vector<vector<int>> ADJ;
vector<bool> red;
vector<bool> blue;

bool dfs(int u, bool is_red) {
    for (int v : ADJ[u]) {
        if (is_red) {
            if (red[v]) {
                return false;
            }
            if (!blue[v]) {
                blue[v] = true;
                if (!dfs(v, false)) {
                    return false;
                }
            }
        } else {
            if (blue[v]) {
                return false;
            }
            if (!red[v]) {
                red[v] = true;
                if (!dfs(v, true)) {
                    return false;
                }
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
        red.resize(V);
        blue.resize(V);
        fill(red.begin(), red.end(), false);
        fill(blue.begin(), blue.end(), false);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            ADJ[u - 1].emplace_back(v - 1);
            ADJ[v - 1].emplace_back(u - 1);
        }
        bool can_make = true;
        for (int i = 0; i < V; i++) {
            if (red[i] || blue[i]) {
                continue;
            }
            red[i] = true;
            if (!dfs(i, true)) {
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
