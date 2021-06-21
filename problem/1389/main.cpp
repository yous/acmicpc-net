#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const short INF = 30000;
int N, M;
short dist[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + N, INF);
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a - 1][b - 1] = 1;
        dist[b - 1][a - 1] = 1;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            short dist_ik = dist[i][k];
            if (dist_ik == INF) {
                continue;
            }
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], static_cast<short>(dist_ik + dist[k][j]));
            }
        }
    }
    int _min = INF * (N - 1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = accumulate(dist[i], dist[i] + N, 0);
        if (sum < _min) {
            _min = sum;
            ans = i + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}
