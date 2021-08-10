#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C;
vector<string> board;
vector<vector<bool>> visited;

int solve(int y, int x, bitset<26>& chars) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || chars[board[ny][nx] - 'a']) {
            continue;
        }
        visited[ny][nx] = true;
        chars[board[ny][nx] - 'a'] = true;
        ans = max(ans, 1 + solve(ny, nx, chars));
        visited[ny][nx] = false;
        chars[board[ny][nx] - 'a'] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    board.resize(R);
    visited.resize(R, vector<bool>(C));
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    bitset<26> chars;
    visited[0][0] = true;
    chars[board[0][0] - 'a'] = true;
    cout << solve(0, 0, chars) << "\n";
    return 0;
}
