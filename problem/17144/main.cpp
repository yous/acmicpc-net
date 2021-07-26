#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int R, C, T;
vector<vector<int>> air[2];
pair<int, int> cleaner[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> T;
    for (int i = 0; i < 2; i++) {
        air[i].resize(R, vector<int>(C));
    }
    int cleaner_idx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> air[0][i][j];
            if (air[0][i][j] == -1) {
                cleaner[cleaner_idx] = {i, j};
                cleaner_idx++;
            }
        }
    }
    for (int t = 0; t < T; t++) {
        vector<vector<int>>& cur_air = air[t % 2];
        vector<vector<int>>& next_air = air[(t % 2) ^ 1];
        for (int i = 0; i < R; i++) {
            fill(next_air[i].begin(), next_air[i].end(), 0);
        }
        for (int i = 0; i < 2; i++) {
            next_air[cleaner[i].first][cleaner[i].second] = -1;
        }
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                int dust = cur_air[y][x];
                if (dust <= 0) {
                    continue;
                }
                next_air[y][x] += dust;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= R || nx < 0 || nx >= C || cur_air[ny][nx] == -1) {
                        continue;
                    }
                    next_air[ny][nx] += dust / 5;
                    next_air[y][x] -= dust / 5;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            int cur_dir = 0;
            int y = cleaner[i].first + dy[cur_dir] * (i == 0 ? 1 : -1),
                x = cleaner[i].second + dx[cur_dir];
            int lo = (i == 0 ? 0 : cleaner[i].first);
            int hi = (i == 0 ? cleaner[i].first + 1 : R);
            while (cur_dir < 4) {
                while (true) {
                    int ny = y + dy[cur_dir] * (i == 0 ? 1 : -1);
                    int nx = x + dx[cur_dir];
                    if (ny < lo || ny >= hi || nx < 0 || nx >= C) {
                        break;
                    } else if (next_air[ny][nx] == -1) {
                        next_air[y][x] = 0;
                        break;
                    }
                    next_air[y][x] = next_air[ny][nx];
                    y = ny;
                    x = nx;
                }
                cur_dir++;
            }
        }
    }
    int ans = 0;
    vector<vector<int>>& final_air = air[T % 2];
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            int dust = final_air[y][x];
            if (dust != -1) {
                ans += dust;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
