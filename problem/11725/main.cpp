#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> ADJ;
vector<int> parent;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N + 1);
    parent.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        ADJ[a].push_back(b);
        ADJ[b].push_back(a);
    }
    queue<pair<int, int>> qu;
    qu.emplace(1, 0);
    while (!qu.empty()) {
        auto& p = qu.front();
        int u = p.first,
            s = p.second;
        qu.pop();
        for (auto& v : ADJ[u]) {
            if (v != s) {
                parent[v] = u;
                qu.emplace(v, u);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}
