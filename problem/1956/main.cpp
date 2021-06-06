#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int V, E;
int dist[401][401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        fill(dist[i], dist[i] + V, INF);
    }
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (dist[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int _min = INF;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < _min) {
            _min = dist[i][i];
        }
    }
    if (_min == INF) {
        cout << "-1\n";
    } else {
        cout << _min << "\n";
    }
    return 0;
}
