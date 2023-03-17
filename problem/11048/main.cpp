#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<short>> maze(N, vector<short>(M));
    for (auto& row : maze) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<vector<int>> cache(N, vector<int>(M, 0));
    cache[0][0] = maze[0][0];
    for (int yx = 0; yx < N + M - 1; yx++) {
        for (int y = max(0, yx - M + 1); y < min(int(N), yx + 1); y++) {
            int x = yx - y;
            if (y > 0) {
                cache[y][x] = max(cache[y][x], maze[y][x] + cache[y - 1][x]);
                if (x > 0) {
                    cache[y][x] = max(cache[y][x], maze[y][x] + cache[y - 1][x - 1]);
                }
            }
            if (x > 0) {
                cache[y][x] = max(cache[y][x], maze[y][x] + cache[y][x - 1]);
            }
        }
    }
    cout << cache[N - 1][M - 1] << "\n";
    return 0;
}
