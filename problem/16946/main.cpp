#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<string> field;
vector<vector<bool>> visited;
vector<vector<bool>> is_wall;
vector<vector<int>> walls;
vector<int> labels;

int dfs(int y, int x, int label) {
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
            continue;
        }
        if (is_wall[ny][nx]) {
            if (walls[ny][nx] != label) {
                field[ny][nx] = (field[ny][nx] - '0' + labels[walls[ny][nx]]) % 10 + '0';
                walls[ny][nx] = label;
            }
            continue;
        }
        visited[ny][nx] = true;
        cnt += dfs(ny, nx, label);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    field.resize(N);
    visited.resize(N, vector<bool>(M));
    is_wall.resize(N, vector<bool>(M));
    walls.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        cin >> field[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (field[i][j] == '1') {
                is_wall[i][j] = true;
            }
        }
    }
    labels.push_back(0);
    int label = 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!is_wall[y][x] && !visited[y][x]) {
                visited[y][x] = true;
                int cnt = dfs(y, x, label);
                labels.push_back(cnt);
                label++;
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (is_wall[y][x]) {
                field[y][x] = (field[y][x] - '0' + labels[walls[y][x]]) % 10 + '0';
            }
        }
        cout << field[y] << "\n";
    }
    return 0;
}
