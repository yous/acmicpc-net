#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<char>> board;

bool tilt(pair<int, int>& ball, int dir) {
    while (board[ball.first][ball.second] == '.') {
        ball.first += dy[dir];
        ball.second += dx[dir];
    }
    if (board[ball.first][ball.second] == 'O') {
        return true;
    } else {
        ball.first -= dy[dir];
        ball.second -= dx[dir];
        return false;
    }
}

int solve(int cnt, pair<int, int>& red, pair<int, int>& blue) {
    if (cnt == 11) {
        return cnt;
    }
    int ans = 11;
    for (int i = 0; i < 4; i++) {
        bool red_first;
        if (dy[i] != 0) {
            red_first = (red.first * dy[i] > blue.first * dy[i]);
        } else {
            red_first = (red.second * dx[i] > blue.second * dx[i]);
        }
        bool first_fall = false,
             second_fall = false;
        pair<int, int> dist1 = (red_first ? red : blue);
        first_fall = tilt(dist1, i);
        if (!first_fall) {
            board[dist1.first][dist1.second] = '#';
        }
        pair<int, int> dist2 = (red_first ? blue : red);
        second_fall = tilt(dist2, i);
        if (!first_fall) {
            board[dist1.first][dist1.second] = '.';
        }
        bool red_fall = (red_first ? first_fall : second_fall),
             blue_fall = (red_first ? second_fall : first_fall);
        if (blue_fall) {
            continue;
        }
        if (red_fall) {
            ans = min(ans, cnt + 1);
        } else {
            ans = min(ans, solve(cnt + 1, (red_first ? dist1 : dist2), (red_first ? dist2 : dist1)));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    board.resize(N);
    pair<int, int> red;
    pair<int, int> blue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == 'R') {
                red = {i, j};
                ch = '.';
            } else if (ch == 'B') {
                blue = {i, j};
                ch = '.';
            }
            board[i].emplace_back(ch);
        }
    }
    int ans = solve(0, red, blue);
    if (ans == 11) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
