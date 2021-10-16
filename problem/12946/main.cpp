#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, -1, 0, 0, 1, 1};
const int dx[] = {0, 1, -1, 1, -1, 0};
int N;
vector<string> board;
vector<vector<short>> color;

bool dfs(int y, int x, int c) {
    int nc = (c == 1 ? 2 : 1);
    for (int i = 0; i < 6; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] != 'X') {
            continue;
        }
        if (color[ny][nx] == c) {
            return false;
        }
        if (color[ny][nx] == 0) {
            color[ny][nx] = nc;
            if (!dfs(ny, nx, nc)) {
                return false;
            }
        }
    }
    return true;
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
    bool paint = false;
    bool match = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 'X') {
                continue;
            }
            paint = true;
            if (color[i][j]) {
                continue;
            }
            color[i][j] = 1;
            if (!dfs(i, j, 1)) {
                match = false;
                break;
            }
        }
        if (!match) {
            break;
        }
    }
    if (!paint) {
        cout << "0\n";
    } else if (match) {
        bool bipart = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (color[i][j] == 2) {
                    bipart = true;
                    break;
                }
            }
            if (bipart) {
                break;
            }
        }
        cout << (bipart ? "2\n" : "1\n");
    } else {
        cout << "3\n";
    }
    return 0;
}
