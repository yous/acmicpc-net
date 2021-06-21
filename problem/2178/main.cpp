#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<string> maze;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        maze.push_back(row);
    }
    queue<pair<int, int>> qu;
    bool found = false;
    int cnt = 1;
    maze[0][0] = '0';
    qu.emplace(0, 0);
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto& p = qu.front();
            int y = p.first,
                x = p.second;
            qu.pop();
            if (y == N - 1 && x == M - 1) {
                found = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || maze[ny][nx] == '0') {
                    continue;
                }
                maze[ny][nx] = '0';
                qu.emplace(ny, nx);
            }
        }
        if (found) {
            break;
        }
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
