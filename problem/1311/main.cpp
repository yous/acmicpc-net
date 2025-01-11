#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> D(N, vector<short>(N));
    for (auto& row : D) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<int> cache(1 << N, INF);
    cache[0] = 0;
    for (int visited = 1; visited < (1 << N); visited++) {
        int cnt = __builtin_popcount(visited);
        for (int n = 0; n < N; n++) {
            if (visited & (1 << n)) {
                cache[visited] = min(cache[visited], D[cnt - 1][n] + cache[visited & ~(1 << n)]);
            }
        }
    }
    cout << cache[(1 << N) - 1] << "\n";
    return 0;
}
