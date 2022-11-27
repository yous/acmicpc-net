#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};
short N;

void dfs(vector<vector<short>>& sea, queue<tuple<short, short, short>>& qu, vector<vector<pair<short, short>>>& visited, short y, short x, short island_num) {
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
        dfs(sea, qu, visited, ny, nx, island_num);
    }
    if (is_edge) {
        qu.emplace(y, x, island_num);
        visited[y][x] = {island_num, 0};
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
    queue<tuple<short, short, short>> qu;
    vector<vector<pair<short, short>>> visited(N, vector<pair<short, short>>(N));
    short island_num = 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (sea[y][x] == -1) {
                dfs(sea, qu, visited, y, x, island_num);
                island_num++;
            }
        }
    }
    short step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x, cur_island] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || sea[ny][nx] == cur_island) {
                    continue;
                }
                if (visited[ny][nx].first != 0) {
                    auto [other_island, other_step] = visited[ny][nx];
                    if (cur_island == other_island) {
                        continue;
                    }
                    cout << step + other_step - 1 << "\n";
                    return 0;
                }
                if (sea[ny][nx] != 0 && sea[ny][nx] != cur_island) {
                    cout << step - 1 << "\n";
                    return 0;
                }
                visited[ny][nx] = {cur_island, step};
                qu.emplace(ny, nx, cur_island);
            }
        }
        step++;
    }
    return 0;
}
