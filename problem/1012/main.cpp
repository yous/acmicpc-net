#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int T;
int M, N, K;
vector<bool> field[50];
vector<bool> visited[50];

void bfs(int sy, int sx) {
    queue<pair<int, int>> qu;
    visited[sy][sx] = true;
    qu.emplace(sy, sx);
    while (!qu.empty()) {
        auto& p = qu.front();
        int y = p.first,
            x = p.second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || !field[ny][nx] || visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = true;
            qu.emplace(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> M >> N >> K;
        for (int i = 0; i < N; i++) {
            field[i].resize(M);
            fill(field[i].begin(), field[i].end(), false);
            visited[i].resize(M);
            fill(visited[i].begin(), visited[i].end(), false);
        }
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = true;
        }
        int cnt = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (field[y][x] && !visited[y][x]) {
                    cnt++;
                    bfs(y, x);
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
