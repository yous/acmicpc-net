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
    vector<string> campus(N);
    short sy = -1;
    short sx = -1;
    for (int i = 0; i < N; i++) {
        cin >> campus[i];
        if (sy != -1) {
            continue;
        }
        for (int j = 0; j < M; j++) {
            if (campus[i][j] == 'I') {
                sy = i;
                sx = j;
                break;
            }
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M));
    int count = 0;
    queue<pair<short, short>> qu;
    visited[sy][sx] = true;
    qu.emplace(sy, sx);
    while (!qu.empty()) {
        auto [y, x] = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            short ny = y + dy[i];
            short nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || campus[ny][nx] == 'X') {
                continue;
            }
            visited[ny][nx] = true;
            if (campus[ny][nx] == 'P') {
                count++;
            }
            qu.emplace(ny, nx);
        }
    }
    if (count > 0) {
        cout << count << "\n";
    } else {
        cout << "TT\n";
    }
    return 0;
}
