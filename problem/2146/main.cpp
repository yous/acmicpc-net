#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};
short N;

void dfs(vector<vector<short>>& sea, vector<pair<short, short>>& edges, short y, short x, short island_num) {
    sea[y][x] = island_num;
    bool is_edge = false;
    for (int i = 0; i < 4; i++) {
        short ny = y + dy[i];
        short nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }
        if (sea[ny][nx] == 0) {
            is_edge = true;
            continue;
        }
        if (sea[ny][nx] != -1) {
            continue;
        }
        dfs(sea, edges, ny, nx, island_num);
    }
    if (is_edge) {
        edges.emplace_back(y, x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<short>> sea(N, vector<short>(N));
    for (auto& row : sea) {
        for (auto& num : row) {
            cin >> num;
            num = -num;
        }
    }
    vector<pair<short, short>> edges;
    short island_num = 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (sea[y][x] == -1) {
                dfs(sea, edges, y, x, island_num);
                island_num++;
            }
        }
    }
    short ans = N * N;
    for (auto [sy, sx] : edges) {
        short cur_island = sea[sy][sx];
        queue<pair<short, short>> qu;
        vector<vector<bool>> visited(N, vector<bool>(N));
        qu.emplace(sy, sx);
        visited[sy][sx] = true;
        short step = 0;
        bool found = false;
        while (!qu.empty()) {
            auto sz = qu.size();
            while (sz-- > 0) {
                auto [y, x] = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    short ny = y + dy[i];
                    short nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N || sea[ny][nx] == cur_island || visited[ny][nx]) {
                        continue;
                    }
                    if (sea[ny][nx] != 0 && sea[ny][nx] != cur_island) {
                        found = true;
                        ans = min(ans, step);
                        break;
                    }
                    visited[ny][nx] = true;
                    qu.emplace(ny, nx);
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
            step++;
        }
    }
    cout << ans << "\n";
    return 0;
}
