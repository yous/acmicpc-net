#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<short>> field(N, vector<short>(M));
    for (auto& row : field) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<int> cache(M);
    cache[0] = field[0][0];
    for (int x = 1; x < M; x++) {
        cache[x] = cache[x - 1] + field[0][x];
    }
    vector<int> next_cache_ltr(M);
    vector<int> next_cache_rtl(M);
    for (int y = 1; y < N; y++) {
        next_cache_ltr[0] = cache[0] + field[y][0];
        for (int x = 1; x < M; x++) {
            next_cache_ltr[x] = max(cache[x] + field[y][x], next_cache_ltr[x - 1] + field[y][x]);
        }
        next_cache_rtl[M - 1] = cache[M - 1] + field[y][M - 1];
        for (int x = M - 2; x >= 0; x--) {
            next_cache_rtl[x] = max(cache[x] + field[y][x], next_cache_rtl[x + 1] + field[y][x]);
        }
        for (int x = 0; x < M; x++) {
            cache[x] = max(next_cache_ltr[x], next_cache_rtl[x]);
        }
    }
    cout << cache[M - 1] << "\n";
    return 0;
}
