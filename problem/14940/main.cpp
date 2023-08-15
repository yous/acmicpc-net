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
    short N, M;
    cin >> N >> M;
    vector<vector<int>> field(N, vector<int>(M));
    int sy, sx;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            if (num == 2) {
                sy = i;
                sx = j;
                field[i][j] = 0;
            } else if (num == 1) {
                field[i][j] = -1;
            } else {
                field[i][j] = num;
            }
        }
    }
    queue<pair<short, short>> qu;
    qu.emplace(sy, sx);
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto& [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || field[ny][nx] != -1) {
                    continue;
                }
                field[ny][nx] = step;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
    for (auto& row : field) {
        cout << row[0];
        for (int i = 1; i < M; i++) {
            cout << " " << row[i];
        }
        cout << "\n";
    }
    return 0;
}
