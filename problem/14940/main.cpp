#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<short>> field(N, vector<short>(M));
    vector<vector<short>> dist(N, vector<short>(M, -1));
    short dist_y = 0;
    short dist_x = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j] == 2) {
                dist_y = i;
                dist_x = j;
            } else if (field[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    queue<pair<short, short>> qu;
    qu.emplace(dist_y, dist_x);
    dist[dist_y][dist_x] = 0;
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || dist[ny][nx] >= 0) {
                    continue;
                }
                qu.emplace(ny, nx);
                dist[ny][nx] = step;
            }
        }
        step++;
    }
    for (auto& row : dist) {
        cout << row[0];
        for (int j = 1; j < M; j++) {
            cout << " " << row[j];
        }
        cout << "\n";
    }
    return 0;
}
