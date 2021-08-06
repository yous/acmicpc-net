#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<short>> paper;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    paper.resize(N, vector<short>(M));
    int cheese_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == 1) {
                cheese_cnt++;
            }
        }
    }
    const pair<int, int> corners[] = {{0, 0}, {0, M - 1}, {N - 1, 0}, {N - 1, M - 1}};
    queue<pair<int, int>> qu;
    for (auto& p : corners) {
        paper[p.first][p.second] = -1;
        qu.emplace(p);
    }
    while (!qu.empty()) {
        auto [y, x] = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || paper[ny][nx] != 0) {
                continue;
            }
            paper[ny][nx] = -1;
            qu.emplace(ny, nx);
        }
    }
    int time = 1;
    while (cheese_cnt > 0) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (paper[y][x] != 1) {
                    continue;
                }
                int air_cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || paper[ny][nx] != -1) {
                        continue;
                    }
                    air_cnt++;
                    if (air_cnt >= 2) {
                        qu.emplace(y, x);
                        cheese_cnt--;
                        break;
                    }
                }
            }
        }
        if (cheese_cnt == 0) {
            cout << time << "\n";
            break;
        }
        while (!qu.empty()) {
            auto [y, x] = qu.front();
            qu.pop();
            paper[y][x] = -1;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || paper[ny][nx] != 0) {
                    continue;
                }
                paper[ny][nx] = -1;
                qu.emplace(ny, nx);
            }
        }
        time++;
    }
    return 0;
}
