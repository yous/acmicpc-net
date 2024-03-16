#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short R, C;
    cin >> R >> C;
    vector<string> maze(R);
    short sy = 0;
    short sx = 0;
    vector<pair<short, short>> fires;
    vector<vector<bool>> visited_fire(R, vector<bool>(C));
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'J') {
                sy = i;
                sx = j;
            } else if (maze[i][j] == 'F') {
                fires.emplace_back(i, j);
                visited_fire[i][j] = true;
            }
        }
    }
    queue<pair<short, short>> qu_fire;
    for (auto [y, x] : fires) {
        for (int i = 0; i < 4; i++) {
            short ny = y + dy[i];
            short nx = x + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || maze[ny][nx] == '#' || visited_fire[ny][nx]) {
                continue;
            }
            visited_fire[ny][nx] = true;
            qu_fire.emplace(ny, nx);
        }
    }
    vector<vector<bool>> visited(R, vector<bool>(C));
    queue<pair<short, short>> qu;
    visited[sy][sx] = true;
    qu.emplace(sy, sx);
    int step = 0;
    bool found = false;
    while (!qu.empty()) {
        auto fire_sz = qu_fire.size();
        while (fire_sz-- > 0) {
            auto [y, x] = qu_fire.front();
            qu_fire.pop();
            maze[y][x] = 'F';
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || maze[ny][nx] == '#' || visited_fire[ny][nx]) {
                    continue;
                }
                visited_fire[ny][nx] = true;
                qu_fire.emplace(ny, nx);
            }
        }
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
                found = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || maze[ny][nx] == '#' || maze[ny][nx] == 'F' || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = true;
                qu.emplace(ny, nx);
            }
        }
        if (found) {
            break;
        }
        step++;
    }
    if (found) {
        cout << step + 1 << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
