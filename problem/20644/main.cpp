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
vector<vector<bool>> visited[500];
vector<vector<bool>> failed[500];
vector<vector<int>> max_sizes;
vector<vector<int>> visited_diff;
vector<vector<int>> y_plus_x;
vector<vector<int>> y_minus_x;

bool check(int y, int x, int sz, int dir) {
    if (failed[sz][y][x]) {
        return false;
    }
    switch (dir) {
        case 0:
            return y_plus_x[y - sz + x][y - sz] >= sz + 1 &&
                y_minus_x[y - sz + N - 1 - x][y - sz] >= sz + 1;
        case 1:
            return y_plus_x[y + x + sz][y] >= sz + 1 &&
                y_minus_x[y + N - 1 - (x - sz)][y] >= sz + 1;
        case 2:
            return y_plus_x[y - sz + x][y - sz] >= sz + 1 &&
                y_minus_x[y + N - 1 - (x - sz)][y] >= sz + 1;
        case 3:
            return y_plus_x[y + x + sz][y] >= sz + 1 &&
                y_minus_x[y - sz + N - 1 - x][y - sz] >= sz + 1;
    }
    return false;
}

void bfs() {
    queue<tuple<int, int, int>> qu;
    int time = 1;
    for (auto [sy, sx] : starts) {
        visited[0][sy][sx] = true;
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
                if (visited[size][ny][nx]) {
                    continue;
                }
                if (!check(ny, nx, size, i)) {
                    failed[size][ny][nx] = true;
                    continue;
                }
                visited[size][ny][nx] = true;
                max_sizes[ny][nx] = size;
                if (time % D == 0) {
                    if (check(ny, nx, size + 1, i) && check(ny, nx, size + 1, i ^ 1)) {
                        visited[size + 1][ny][nx] = true;
                        max_sizes[ny][nx] = size + 1;
                        qu.emplace(ny, nx, size + 1);
                    } else {
                        failed[size + 1][ny][nx] = true;
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
    for (int i = 0; i < 500; i++) {
        visited[i].resize(N, vector<bool>(N));
        failed[i].resize(N, vector<bool>(N));
    }
    max_sizes.resize(N, vector<int>(N, -1));
    visited_diff.resize(N, vector<int>(N));
    y_plus_x.resize(N * 2 - 1);
    y_minus_x.resize(N * 2 - 1);
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
    for (int yx = 0; yx <= N * 2 - 2; yx++) {
        int sharp = -1;
        int sy = max(0, yx - (N - 1));
        for (int i = 0; i < sy; i++) {
            y_plus_x[yx].push_back(0);
        }
        for (int y = sy; y <= min(N - 1, yx); y++) {
            int x = yx - y;
            if (sharp >= 0) {
                y_plus_x[yx].push_back(sharp);
                sharp--;
                continue;
            }
            sharp = 0;
            int cy = y,
                cx = x;
            while (cy <= min(N - 1, yx) && farm[cy][cx] != '#') {
                sharp++;
                cy++;
                cx--;
            }
            y_plus_x[yx].push_back(sharp);
            sharp--;
        }
    }
    for (int yx = 0; yx <= N * 2 - 2; yx++) {
        int sharp = -1;
        int sy = max(0, yx - (N - 1));
        for (int i = 0; i < sy; i++) {
            y_minus_x[yx].push_back(0);
        }
        for (int y = sy; y <= min(N - 1, yx); y++) {
            int x = y + N - 1 - yx;
            if (sharp >= 0) {
                y_minus_x[yx].push_back(sharp);
                sharp--;
                continue;
            }
            sharp = 0;
            int cy = y,
                cx = x;
            while (cy <= min(N - 1, yx) && farm[cy][cx] != '#') {
                sharp++;
                cy++;
                cx++;
            }
            y_minus_x[yx].push_back(sharp);
            sharp--;
        }
    }
    bfs();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int sz = max_sizes[y][x];
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
