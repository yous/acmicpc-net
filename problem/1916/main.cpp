#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<vector<pair<int, int>>> ADJ;
vector<int> dist;

void spfa(int s) {
    queue<int> qu;
    vector<bool> in_q(N);
    dist[s] = 0;
    qu.push(s);
    in_q[s] = true;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto& p : ADJ[u]) {
            int v = p.first,
                w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!in_q[v]) {
                    qu.push(v);
                    in_q[v] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    ADJ.resize(N);
    dist.resize(N, INF);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        ADJ[a - 1].emplace_back(b - 1, w);
    }
    int a, b;
    cin >> a >> b;
    spfa(a - 1);
    cout << dist[b - 1] << "\n";
    return 0;
}
