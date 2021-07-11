#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};
int N;
char space[20][20];
bool visited[20][20];

tuple<int, int, int> next_pos(int sy, int sx, int shark_sz) {
    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + N, false);
    }
    queue<pair<int, int>> qu;
    visited[sy][sx] = true;
    qu.emplace(sy, sx);
    int step = 0;
    vector<pair<int, int>> found;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto& p = qu.front();
            int y = p.first,
                x = p.second;
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || space[ny][nx] - '0' > shark_sz) {
                    continue;
                }
                visited[ny][nx] = true;
                if (space[ny][nx] != '0' && space[ny][nx] - '0' < shark_sz) {
                    found.emplace_back(ny, nx);
                }
                qu.emplace(ny, nx);
            }
        }
        step++;
        if (!found.empty()) {
            pair<int, int> np = found[0];
            for (int i = 1, sz = found.size(); i < sz; i++) {
                np = min(np, found[i]);
            }
            space[np.first][np.second] = '0';
            return {np.first, np.second, step};
        }
    }
    return {-1, -1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    pair<int, int> shark;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] == '9') {
                shark = {i, j};
            }
        }
    }
    int shark_sz = 2;
    int eat_count = 0;
    int total_time = 0;
    space[shark.first][shark.second] = '0';
    int y, x, time;
    tie(y, x, time) = next_pos(shark.first, shark.second, shark_sz);
    while (y != -1 && x != -1) {
        total_time += time;
        eat_count++;
        if (eat_count == shark_sz) {
            eat_count = 0;
            shark_sz++;
        }
        tie(y, x, time) = next_pos(y, x, shark_sz);
    }
    cout << total_time << "\n";
    return 0;
}
