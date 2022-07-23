#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void bfs(queue<pair<short, short>>& qu, vector<vector<int>>& visited, vector<vector<short>>& meal, short N, short M) {
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            short cur_jump = meal[y][x];
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i] * cur_jump;
                int nx = x + dx[i] * cur_jump;
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] != INF) {
                    continue;
                }
                visited[ny][nx] = step;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    short frog_y, frog_x, house_y, house_x;
    cin >> frog_y >> frog_x >> house_y >> house_x;
    frog_y--;
    frog_x--;
    house_y--;
    house_x--;
    vector<vector<short>> meal(N, vector<short>(M));
    for (auto& row : meal) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    if (frog_y == house_y && frog_x == house_x) {
        cout << "0\n";
        return 0;
    }
    vector<vector<vector<pair<short, short>>>> graph(N, vector<vector<pair<short, short>>>(M, vector<pair<short, short>>()));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            short cur_jump = meal[y][x];
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i] * cur_jump;
                int nx = x + dx[i] * cur_jump;
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                    continue;
                }
                graph[ny][nx].emplace_back(y, x);
            }
        }
    }
    vector<vector<int>> frog_visited(N, vector<int>(M, INF));
    frog_visited[frog_y][frog_x] = 0;
    queue<pair<short, short>> qu;
    qu.emplace(frog_y, frog_x);
    bfs(qu, frog_visited, meal, N, M);
    vector<vector<int>> house_visited(N, vector<int>(M, INF));
    house_visited[house_y][house_x] = 0;
    qu.emplace(house_y, house_x);
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (auto [ny, nx] : graph[y][x]) {
                if (house_visited[ny][nx] != INF) {
                    continue;
                }
                house_visited[ny][nx] = step;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
    int min_step = frog_visited[house_y][house_x];
    vector<int> house_row_min(N, INF);
    for (int y = 0; y < N; y++) {
        int& min_val = house_row_min[y];
        for (int x = 0; x < M; x++) {
            min_val = min(min_val, house_visited[y][x]);
        }
    }
    vector<int> house_col_min(M, INF);
    for (int x = 0; x < M; x++) {
        int& min_val = house_col_min[x];
        for (int y = 0; y < N; y++) {
            min_val = min(min_val, house_visited[y][x]);
        }
    }
    for (int y = 0; y < N; y++) {
        bool has_row = (house_row_min[y] != INF);
        for (int x = 0; x < M; x++) {
            int frog = frog_visited[y][x];
            if (frog == INF) {
                continue;
            }
            if (has_row) {
                min_step = min(min_step, frog + house_row_min[y] + 1);
            }
            if (house_col_min[x] != INF) {
                min_step = min(min_step, frog + house_col_min[x] + 1);
            }
        }
    }
    if (min_step == INF) {
        cout << "-1\n";
    } else {
        cout << min_step << "\n";
    }
    return 0;
}
