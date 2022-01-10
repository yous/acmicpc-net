#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> cache(N, vector<int>(M, 0));
    cache[0][0] = 1;
    for (int i = 0; i < N + M - 2; i++) {
        for (int y = max(0, i - (M - 1)); y <= min(N - 1, i); y++) {
            int x = i - y;
            if (x < M - 1) {
                cache[y][x + 1] = (cache[y][x + 1] + cache[y][x]) % MOD;
                if (y < N - 1) {
                    cache[y + 1][x + 1] = (cache[y + 1][x + 1] + cache[y][x]) % MOD;
                }
            }
            if (y < N - 1) {
                cache[y + 1][x] = (cache[y + 1][x] + cache[y][x]) % MOD;
            }
        }
    }
    cout << cache[N - 1][M - 1] << "\n";
    return 0;
}
