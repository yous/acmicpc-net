#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short INF = 30000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<short>> graph(N, vector<short>(N, INF));
    vector<vector<short>> next_stop(N, vector<short>(N));
    for (int i = 0; i < N; i++) {
        graph[i][i] = 0;
        for (int j = 0; j < N; j++) {
            next_stop[i][j] = j;
        }
    }
    for (int i = 0; i < M; i++) {
        short a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (graph[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next_stop[i][j] = next_stop[i][k];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << "-";
        } else {
            cout << next_stop[i][0] + 1;
        }
        for (int j = 1; j < N; j++) {
            if (i == j) {
                cout << " -";
            } else {
                cout << " " << next_stop[i][j] + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
