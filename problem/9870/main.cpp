#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, K, Q;
int dist[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        short u, v;
        int d;
        cin >> u >> v >> d;
        dist[u][v] = min(dist[u][v], d);
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int valid_num = 0;
    long long sum = 0;
    for (int i = 0; i < Q; i++) {
        short a, b;
        cin >> a >> b;
        int _min = INF;
        for (int k = 1; k <= K; k++) {
            if (dist[a][k] == INF || dist[k][b] == INF) {
                continue;
            }
            _min = min(_min, dist[a][k] + dist[k][b]);
        }
        if (_min != INF) {
            valid_num++;
            sum += _min;
        }
    }
    cout << valid_num << "\n";
    cout << sum << "\n";
    return 0;
}
