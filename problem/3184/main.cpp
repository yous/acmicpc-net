#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C;
vector<string> field;
vector<vector<bool>> visited;

pair<int, int> dfs(int y, int x) {
    int sheep = 0;
    int wolf = 0;
    visited[y][x] = true;
    if (field[y][x] == 'o') {
        sheep++;
    } else if (field[y][x] == 'v') {
        wolf++;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || field[ny][nx] == '#') {
            continue;
        }
        auto ret = dfs(ny, nx);
        sheep += ret.first;
        wolf += ret.second;
    }
    return {sheep, wolf};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    field.resize(R);
    visited.resize(R, vector<bool>(C));
    for (string& row : field) {
        cin >> row;
    }
    int sheep = 0;
    int wolf = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && field[i][j] != '#') {
                auto ret = dfs(i, j);
                if (ret.first > ret.second) {
                    sheep += ret.first;
                } else {
                    wolf += ret.second;
                }
            }
        }
    }
    cout << sheep << " " << wolf << "\n";
    return 0;
}
