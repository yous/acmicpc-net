#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<vector<short>> board(N, vector<short>(M));
    for (auto& row : board) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    if (board[0][0] > 13) {
        cout << "BAD\n";
        return 0;
    }
    vector<vector<vector<short>>> visited(N, vector<vector<short>>(M, vector<short>(3, -1)));
    queue<tuple<short, short, short, short>> qu;
    qu.emplace(0, 0, 0, 0);
    while (!qu.empty()) {
        auto [y, x, state, count] = qu.front();
        qu.pop();
        if (visited[y][x][state] != -1 && visited[y][x][state] <= count) {
            continue;
        }
        visited[y][x][state] = count;
        if (y == N - 1 && x == M - 1) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }
            if (board[ny][nx] <= 13) {
                if (state == 0) {
                    continue;
                } else if (state == 1) {
                    qu.emplace(ny, nx, 2, count);
                } else {
                    qu.emplace(ny, nx, 0, count + 1);
                }
            } else {
                if (state == 0) {
                    qu.emplace(ny, nx, 1, count);
                } else if (state == 1) {
                    continue;
                } else {
                    qu.emplace(ny, nx, 1, count + 1);
                }
            }
        }
    }
    int ans = 0;
    if (visited[N - 1][M - 1][1] >= 0) {
        ans += visited[N - 1][M - 1][1] + 1;
    }
    if (visited[N - 1][M - 1][2] >= 0) {
        ans += visited[N - 1][M - 1][2] + 1;
    }
    if (ans > 0) {
        cout << ans << "\n";
    } else {
        cout << "BAD\n";
    }
    return 0;
}
