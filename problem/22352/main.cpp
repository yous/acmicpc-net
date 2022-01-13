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
    int N, M;
    cin >> N >> M;
    vector<vector<short>> before(N, vector<short>(M));
    vector<vector<short>> after(N, vector<short>(M));
    for (auto& row : before) {
        for (short& num : row) {
            cin >> num;
        }
    }
    for (auto& row : after) {
        for (short& num : row) {
            cin >> num;
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(M));
    bool changed = false;
    queue<pair<int, int>> qu;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) {
                continue;
            }
            if (before[i][j] != after[i][j]) {
                if (changed) {
                    cout << "NO\n";
                    return 0;
                }
                changed = true;
                short before_val = before[i][j];
                short after_val = after[i][j];
                visited[i][j] = true;
                qu.emplace(i, j);
                while (!qu.empty()) {
                    auto [y, x] = qu.front();
                    qu.pop();
                    for (int i = 0; i < 4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];
                        if (ny < 0 || ny >= N || nx < 0 || nx >= M || before[ny][nx] != before_val || visited[ny][nx]) {
                            continue;
                        }
                        if (after[ny][nx] != after_val) {
                            cout << "NO\n";
                            return 0;
                        }
                        visited[ny][nx] = true;
                        qu.emplace(ny, nx);
                    }
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
