#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M, K, Q;
int graph[201][201];
int dist[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
            dist[i][j] = INF;
        }
        graph[i][i] = 0;
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        short u, v;
        int d;
        cin >> u >> v >> d;
        graph[u][v] = min(graph[u][v], d);
        if (u <= K || v <= K) {
            dist[u][v] = min(dist[u][v], d);
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (graph[i][k] == INF) {
                continue;
            }
            for (int j = 1; j <= N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            if (graph[i][k] == INF) {
                continue;
            }
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int valid_num = 0;
    long long sum = 0;
    for (int i = 0; i < Q; i++) {
        short a, b;
        cin >> a >> b;
        if (dist[a][b] != INF) {
            valid_num++;
            sum += dist[a][b];
        }
    }
    cout << valid_num << "\n";
    cout << sum << "\n";
    return 0;
}
