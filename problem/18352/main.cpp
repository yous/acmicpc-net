#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K, X;
    cin >> N >> M >> K >> X;
    vector<vector<int>> ADJ(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ADJ[a - 1].emplace_back(b - 1);
    }
    vector<bool> visited(N);
    vector<bool> ans(N);
    queue<int> qu;
    visited[X - 1] = true;
    qu.emplace(X - 1);
    int step = 1;
    bool found = false;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int u = qu.front();
            qu.pop();
            for (int v : ADJ[u]) {
                if (visited[v]) {
                    continue;
                }
                visited[v] = true;
                if (step == K) {
                    found = true;
                    ans[v] = true;
                } else {
                    qu.emplace(v);
                }
            }
        }
        if (step == K) {
            break;
        }
        step++;
    }
    if (found) {
        for (int i = 0; i < N; i++) {
            if (ans[i]) {
                cout << i + 1 << "\n";
            }
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}
