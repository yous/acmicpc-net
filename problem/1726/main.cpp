#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const short itod[] = { 0, 2, 1, 3 };
const short dy[] = { 0, 1, 0, -1 };
const short dx[] = { 1, 0, -1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short M, N;
    cin >> M >> N;
    vector<vector<bool>> field(M, vector<bool>(N));
    for (auto& row : field) {
        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            row[i] = num == 1;
        }
    }
    short s_y, s_x, s_d;
    cin >> s_y >> s_x >> s_d;
    s_y--;
    s_x--;
    s_d = itod[s_d - 1];
    short e_y, e_x, e_d;
    cin >> e_y >> e_x >> e_d;
    e_y--;
    e_x--;
    e_d = itod[e_d - 1];
    int step = 0;
    vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(4)));
    queue<tuple<short, short, short>> qu;
    visited[s_y][s_x][s_d] = true;
    qu.emplace(s_y, s_x, s_d);
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto& [cy, cx, cd] = qu.front();
            qu.pop();
            if (cy == e_y && cx == e_x && cd == e_d) {
                cout << step << "\n";
                return 0;
            }
            for (int i = 1; i <= 3; i++) {
                short ny = cy + dy[cd] * i;
                short nx = cx + dx[cd] * i;
                if (ny < 0 || ny >= M || nx < 0 || nx >= N || field[ny][nx]) {
                    break;
                }
                if (visited[ny][nx][cd]) {
                    continue;
                }
                visited[ny][nx][cd] = true;
                qu.emplace(ny, nx, cd);
            }
            if (!visited[cy][cx][(cd + 3) % 4]) {
                visited[cy][cx][(cd + 3) % 4] = true;
                qu.emplace(cy, cx, (cd + 3) % 4);
            }
            if (!visited[cy][cx][(cd + 1) % 4]) {
                visited[cy][cx][(cd + 1) % 4] = true;
                qu.emplace(cy, cx, (cd + 1) % 4);
            }
        }
        step++;
    }
    return 0;
}
