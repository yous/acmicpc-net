#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1e9;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    matrix.resize(N);
    visited.resize(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            matrix[i].push_back(ch - '0');
        }
    }
    int step = 2;
    queue<pair<int, int>> qu;
    visited[0][0] = true;
    qu.emplace(0, 0);
    int without_break;
    if (N == 1 && M == 1) {
        without_break = 1;
    } else {
        without_break = INF;
    }
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = true;
                if (ny == N - 1 && nx == M - 1) {
                    without_break = step;
                }
                if (matrix[ny][nx] == 1) {
                    matrix[ny][nx] = step;
                } else {
                    qu.emplace(ny, nx);
                }
            }
        }
        step++;
    }
    for (int i = 0; i < N; i++) {
        fill(visited[i].begin(), visited[i].end(), false);
    }
    step = 1;
    visited[N - 1][M - 1] = true;
    qu.emplace(N - 1, M - 1);
    int with_break = INF;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = true;
                if (matrix[ny][nx] > 1) {
                    with_break = min(with_break, matrix[ny][nx] + step);
                } else if (matrix[ny][nx] == 0) {
                    qu.emplace(ny, nx);
                }
            }
        }
        step++;
    }
    if (without_break < INF || with_break < INF) {
        cout << min(without_break, with_break) << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
