#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C;
vector<string> board;

int solve(int y, int x, bitset<26>& chars) {
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C || chars[board[ny][nx] - 'A']) {
            continue;
        }
        chars[board[ny][nx] - 'A'] = true;
        ans = max(ans, 1 + solve(ny, nx, chars));
        chars[board[ny][nx] - 'A'] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    bitset<26> chars;
    chars[board[0][0] - 'A'] = true;
    cout << solve(0, 0, chars) << "\n";
    return 0;
}
