#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short INF = 20000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short N, P, Q;
        cin >> N >> P >> Q;
        vector<short> people(N);
        for (short& num: people) {
            cin >> num;
        }
        vector<vector<short>> graph(P, vector<short>(P, INF));
        for (int i = 0; i < P; i++) {
            graph[i][i] = 0;
        }
        for (int i = 0; i < Q; i++) {
            short u, v, w;
            cin >> u >> v >> w;
            graph[u - 1][v - 1] = min(graph[u - 1][v - 1], w);
            graph[v - 1][u - 1] = min(graph[v - 1][u - 1], w);
        }
        for (int k = 0; k < P; k++) {
            for (int i = 0; i < P; i++) {
                if (graph[i][k] == INF) {
                    continue;
                }
                for (int j = 0; j < P; j++) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        short ans = -1;
        long long ans_dist = 1LL * 10000 * 10000 * 100;
        for (int i = 0; i < P; i++) {
            long long res = 0;
            bool found = true;
            for (short person : people) {
                if (graph[i][person - 1] == INF) {
                    found = false;
                    break;
                }
                res += graph[i][person - 1] * graph[i][person - 1];
            }
            if (found && ans_dist > res) {
                ans = i + 1;
                ans_dist = res;
            }
        }
        cout << ans << " " << ans_dist << "\n";
    }
    return 0;
}
