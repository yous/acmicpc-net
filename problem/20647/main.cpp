#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> ADJ;
vector<bool> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    ADJ.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        ADJ[a - 1].push_back(b - 1);
        ADJ[b - 1].push_back(a - 1);
    }
    visited.resize(N);
    queue<int> qu;
    visited[0] = true;
    int time_sum = 0;
    qu.push(0);
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int u = qu.front();
            qu.pop();
            int neighbor = 0;
            for (auto v : ADJ[u]) {
                if (!visited[v]) {
                    neighbor++;
                    visited[v] = true;
                    qu.push(v);
                }
            }
            int cow = 1;
            while (cow < neighbor + 1) {
                cow *= 2;
                time_sum++;
            }
            time_sum += neighbor;
        }
    }
    cout << time_sum << "\n";
    return 0;
}
