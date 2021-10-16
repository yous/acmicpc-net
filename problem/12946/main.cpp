#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, -1, 0, 0, 1, 1};
const int dx[] = {0, 1, -1, 1, -1, 0};
int N;
vector<string> board;
vector<vector<short>> color;

int dfs(int y, int x, int c) {
    int ret = 1;
    int nc = (c == 1 ? 2 : 1);
    for (int i = 0; i < 6; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] != 'X') {
            continue;
        }
        if (color[ny][nx] == c) {
            return 3;
        }
        if (color[ny][nx] == 0) {
            color[ny][nx] = nc;
            if (dfs(ny, nx, nc) == 3) {
                return 3;
            }
            ret = 2;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    board.resize(N);
    color.resize(N, vector<short>(N));
    for (string& row : board) {
        cin >> row;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 'X') {
                continue;
            }
            if (color[i][j]) {
                continue;
            }
            color[i][j] = 1;
            ans = max(ans, dfs(i, j, 1));
            if (ans == 3) {
                break;
            }
        }
        if (ans == 3) {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
