#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    vector<vector<short>> next_city(N, vector<short>(N));
    for (int i = 0; i < N; i++) {
        graph[i][i] = 0;
        for (int j = 0; j < N; j++) {
            next_city[i][j] = j;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (graph[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next_city[i][j] = next_city[i][k];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (graph[i][0] == INF) {
            graph[i][0] = 0;
        }
        cout << graph[i][0];
        for (int j = 1; j < N; j++) {
            if (graph[i][j] == INF) {
                graph[i][j] = 0;
            }
            cout << " " << graph[i][j];
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 0) {
                cout << "0\n";
                continue;
            }
            int cnt = 2;
            int city = next_city[i][j];
            while (city != j) {
                city = next_city[city][j];
                cnt++;
            }
            cout << cnt << " " << i + 1;
            city = next_city[i][j];
            while (city != j) {
                cout << " " << city + 1;
                city = next_city[city][j];
            }
            cout << " " << city + 1 << "\n";
        }
    }
    return 0;
}
