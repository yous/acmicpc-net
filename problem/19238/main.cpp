#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 0, 0, 1};
const short dx[] = {0, -1, 1, 0};
short N;

short bfs(short& sy, short& sx, int& fuel, short dest, vector<vector<short>>& field) {
    if (fuel == 0) {
        return -1;
    }
    vector<vector<bool>> visited(N, vector<bool>(N));
    queue<short> qu;
    visited[sy][sx] = true;
    qu.emplace(sy * N + sx);
    int step = 0;
    vector<pair<short, short>> ans;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            short yx = qu.front();
            qu.pop();
            short y = yx / N;
            short x = yx % N;
            if ((dest < 0 && field[y][x] >= 0) || (dest >= 0 && dest == y * N + x)) {
                ans.emplace_back(y, x);
                continue;
            }
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || field[ny][nx] == -2 || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = true;
                qu.emplace(ny * N + nx);
            }
        }
        if (!ans.empty()) {
            sort(ans.begin(), ans.end());
            sy = ans[0].first;
            sx = ans[0].second;
            fuel -= step;
            return step;
        }
        step++;
        if (fuel < step) {
            return -1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short M;
    int fuel;
    cin >> N >> M >> fuel;
    vector<vector<short>> field(N, vector<short>(N, -1));
    for (auto& row : field) {
        for (auto& num : row) {
            cin >> num;
            num = -num - 1;
        }
    }
    short sy, sx;
    cin >> sy >> sx;
    sy--;
    sx--;
    for (int i = 0; i < M; i++) {
        short y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        field[y1 - 1][x1 - 1] = (y2 - 1) * N + x2 - 1;
    }
    for (int i = 0; i < M; i++) {
        short ret = bfs(sy, sx, fuel, -1, field);
        if (ret < 0) {
            cout << "-1\n";
            return 0;
        }
        short dest = field[sy][sx];
        field[sy][sx] = -1;
        ret = bfs(sy, sx, fuel, dest, field);
        if (ret < 0) {
            cout << "-1\n";
            return 0;
        }
        fuel += ret * 2;
    }
    cout << fuel << "\n";
    return 0;
}
