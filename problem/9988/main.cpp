#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
int ADJ[250][250];
vector<int> dist;
vector<int> prev_n;
vector<int> dist2;

void spfa(int s, vector<int>& dist) {
    vector<bool> in_q(N);
    queue<int> qu;
    qu.push(s);
    dist[s] = 0;
    prev_n[s] = -1;
    in_q[s] = true;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        in_q[u] = false;
        for (int v = 0; v < N; v++) {
            if (v == u) {
                continue;
            }
            int l = ADJ[u][v];
            if (l == INF) {
                continue;
            }
            if (dist[u] + l < dist[v]) {
                dist[v] = dist[u] + l;
                prev_n[v] = u;
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
    dist.resize(N);
    prev_n.resize(N);
    dist2.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ADJ[i][j] = INF;
        }
        ADJ[i][i] = 0;
        dist[i] = INF;
    }
    for (int i = 0; i < M; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        ADJ[a - 1][b - 1] = l;
        ADJ[b - 1][a - 1] = l;
    }
    spfa(0, dist);
    int u = N - 1;
    int pu = prev_n[N - 1];
    int max_diff = 0;
    while (pu != -1) {
        ADJ[pu][u] *= 2;
        fill(dist2.begin(), dist2.end(), INF);
        spfa(0, dist2);
        max_diff = max(max_diff, dist2[N - 1] - dist[N - 1]);
        ADJ[pu][u] /= 2;
        u = pu;
        pu = prev_n[u];
    }
    cout << max_diff << "\n";
    return 0;
}
