#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<char>> office;

int get_safe(vector<vector<char>> office) {
    queue<pair<int, int>> qu;
    int safe_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (office[i][j] == '2') {
                qu.emplace(i, j);
            } else if (office[i][j] == '0') {
                safe_cnt++;
            }
        }
    }
    while (!qu.empty()) {
        auto& p = qu.front();
        int y = p.first,
            x = p.second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || office[ny][nx] != '0') {
                continue;
            }
            office[ny][nx] = '2';
            safe_cnt--;
            qu.emplace(ny, nx);
        }
    }
    return safe_cnt;
}

int solve(int cnt, int y, int x, vector<vector<char>>& office) {
    if (cnt == 3) {
        return get_safe(office);
    }
    int ans = 0;
    for (int j = x; j < M; j++) {
        if (office[y][j] == '0') {
            office[y][j] = '1';
            ans = max(ans, solve(cnt + 1, y, j, office));
            office[y][j] = '0';
        }
    }
    for (int i = y + 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (office[i][j] == '0') {
                office[i][j] = '1';
                ans = max(ans, solve(cnt + 1, i, j, office));
                office[i][j] = '0';
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    office.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
        }
    }
    cout << solve(0, 0, 0, office) << "\n";
    return 0;
}
