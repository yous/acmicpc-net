#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, D;
vector<string> farm;
vector<pair<int, int>> starts;
vector<vector<short>> max_sizes;
vector<vector<short>> visited_diff;
vector<vector<short>> y_plus_x;
vector<vector<short>> y_minus_x;

bool check(int y, int x, short sz, int dir) {
    switch (dir) {
        case 0:
            return y_plus_x[y + x - sz][y] >= sz + 1 &&
                y_minus_x[y + N - 1 - (x + sz)][y] >= sz + 1;
        case 1:
            return y_plus_x[y + sz + x][y + sz] >= sz + 1 &&
                y_minus_x[y + sz + N - 1 - x][y + sz] >= sz + 1;
        case 2:
            return y_plus_x[y + x - sz][y] >= sz + 1 &&
                y_minus_x[y + sz + N - 1 - x][y + sz] >= sz + 1;
        case 3:
            return y_plus_x[y + sz + x][y + sz] >= sz + 1 &&
                y_minus_x[y + N - 1 - (x + sz)][y] >= sz + 1;
    }
    return false;
}

void bfs() {
    queue<tuple<int, int, short>> qu;
    int time = 1;
    for (auto [sy, sx] : starts) {
        max_sizes[sy][sx] = 0;
        qu.emplace(sy, sx, 0);
    }
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [y, x, size] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (farm[ny][nx] == '#') {
                    continue;
                }
                if (max_sizes[ny][nx] >= size) {
                    continue;
                }
                if (!check(ny, nx, size, i)) {
                    continue;
                }
                max_sizes[ny][nx] = size;
                if (time % D == 0) {
                    if (check(ny, nx, size + 1, i) && check(ny, nx, size + 1, i ^ 1)) {
                        max_sizes[ny][nx] = size + 1;
                        qu.emplace(ny, nx, size + 1);
                    }
                } else {
                    qu.emplace(ny, nx, size);
                }
            }
        }
        time++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> D;
    max_sizes.resize(N, vector<short>(N, -1));
    visited_diff.resize(N, vector<short>(N));
    y_plus_x.resize(N * 2 - 1, vector<short>(N));
    y_minus_x.resize(N * 2 - 1, vector<short>(N));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        farm.push_back(row);
        for (int j = 0; j < N; j++) {
            if (row[j] == 'S') {
                starts.emplace_back(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (farm[i][j] == '#') {
                continue;
            }
            int line = i + j;
            y_plus_x[line][i] = y_plus_x[line][i - 1] + 1;
            line = i + N - 1 - j;
            y_minus_x[line][i] = y_minus_x[line][i - 1] + 1;
        }
    }
    bfs();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            short sz = max_sizes[y][x];
            for (int i = -sz; i <= sz; i++) {
                visited_diff[y + i][x + abs(i) - sz]++;
                visited_diff[y + i][x + sz - abs(i) + 1]--;
            }
        }
    }
    int ans = 0;
    for (int y = 0; y < N; y++) {
        int cnt = 0;
        for (int x = 0; x < N; x++) {
            cnt += visited_diff[y][x];
            if (cnt > 0) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
