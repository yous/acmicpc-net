#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L;
    cin >> N >> L;
    vector<vector<int>> graph(N + L);
    for (int line = 0; line < L; line++) {
        while (true) {
            int num;
            cin >> num;
            if (num == -1) {
                break;
            }
            num--;
            graph[num].emplace_back(N + line);
            graph[N + line].emplace_back(num);
        }
    }
    int st, ed;
    cin >> st >> ed;
    st--;
    ed--;
    if (st == ed) {
        cout << "0\n";
        return 0;
    }
    vector<bool> visited(N + L);
    queue<int> qu;
    int step = 0;
    visited[st] = true;
    qu.emplace(st);
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto u = qu.front();
            qu.pop();
            if (u == ed) {
                cout << step / 2 - 1 << "\n";
                return 0;
            }
            for (auto v : graph[u]) {
                if (visited[v]) {
                    continue;
                }
                visited[v] = true;
                qu.emplace(v);
            }
        }
        step++;
    }
    cout << "-1\n";
    return 0;
}
