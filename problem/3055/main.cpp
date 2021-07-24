#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C;
vector<vector<char>> forest;
vector<vector<bool>> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    forest.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C));
    pair<int, int> start;
    queue<pair<int, int>> water_qu;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> forest[i][j];
            switch (forest[i][j]) {
                case 'S':
                    start = {i, j};
                    forest[i][j] = '.';
                    break;
                case '*':
                    water_qu.emplace(i, j);
                    break;
            }
        }
    }
    queue<pair<int, int>> qu;
    visited[start.first][start.second] = true;
    qu.push(start);
    int time = 0;
    bool exited = false;
    while (!qu.empty()) {
        if (!water_qu.empty()) {
            auto sz = water_qu.size();
            while (sz-- > 0) {
                auto [y, x] = water_qu.front();
                water_qu.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C || forest[ny][nx] != '.') {
                        continue;
                    }
                    forest[ny][nx] = '*';
                    water_qu.emplace(ny, nx);
                }
            }
        }
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            if (forest[y][x] == 'D') {
                exited = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || (forest[ny][nx] != '.' && forest[ny][nx] != 'D') || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = true;
                qu.emplace(ny, nx);
            }
        }
        if (exited) {
            break;
        }
        time++;
    }
    if (exited) {
        cout << time << "\n";
    } else {
        cout << "KAKTUS\n";
    }
    return 0;
}
