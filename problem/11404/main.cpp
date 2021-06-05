#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
int cost[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        fill(cost[i], cost[i] + N, INF);
        cost[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a - 1][b - 1] = min(cost[a - 1][b - 1], c);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            if (cost[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cost[i][j] == INF) {
                cout << "0";
            } else {
                cout << cost[i][j];
            }
            if (j < N - 1) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
    }
    return 0;
}
