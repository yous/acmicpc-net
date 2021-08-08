#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, X;
vector<vector<pair<int, int>>> ADJ;
vector<vector<pair<int, int>>> ADJ_REV;
vector<int> dist;
vector<int> dist_rev;

void spfa(int s, bool rev) {
    vector<vector<pair<int, int>>>& adj = (rev ? ADJ_REV : ADJ);
    vector<int>& d = (rev ? dist_rev : dist);
    queue<int> qu;
    vector<bool> in_q(N);
    d[s] = 0;
    in_q[s] = true;
    qu.push(s);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (auto [v, w] : adj[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!in_q[v]) {
                    in_q[v] = true;
                    qu.push(v);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    ADJ.resize(N);
    ADJ_REV.resize(N);
    dist.resize(N, INF);
    dist_rev.resize(N, INF);
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        ADJ[a - 1].emplace_back(b - 1, t);
        ADJ_REV[b - 1].emplace_back(a - 1, t);
    }
    spfa(X - 1, false);
    spfa(X - 1, true);
    int max_d = 0;
    for (int i = 0; i < N; i++) {
        int d = dist[i] + dist_rev[i];
        if (max_d < d) {
            max_d = d;
        }
    }
    cout << max_d << "\n";
    return 0;
}
