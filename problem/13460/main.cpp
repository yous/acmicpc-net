#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-10, 10, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<char>> board;

bool tilt(int& ball, int dir) {
    while (board[ball / 10][ball % 10] == '.') {
        ball += dy[dir];
        ball += dx[dir];
    }
    if (board[ball / 10][ball % 10] == 'O') {
        return true;
    } else {
        ball -= dy[dir];
        ball -= dx[dir];
        return false;
    }
}

int solve(int start) {
    queue<int> qu;
    vector<bool> visited(10000);
    visited[start] = true;
    qu.emplace(start);
    int step = 1;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            int redblue = qu.front();
            qu.pop();
            int red = redblue / 100;
            int blue = redblue % 100;
            for (int i = 0; i < 4; i++) {
                bool red_first;
                if (dy[i] != 0) {
                    red_first = (red / 10 * dy[i] > blue / 10 * dy[i]);
                } else {
                    red_first = (red % 10 * dx[i] > blue % 10 * dx[i]);
                }
                bool first_fall = false,
                     second_fall = false;
                int dist1 = (red_first ? red : blue);
                first_fall = tilt(dist1, i);
                if (!first_fall) {
                    board[dist1 / 10][dist1 % 10] = '#';
                }
                int dist2 = (red_first ? blue : red);
                second_fall = tilt(dist2, i);
                if (!first_fall) {
                    board[dist1 / 10][dist1 % 10] = '.';
                }
                bool red_fall = (red_first ? first_fall : second_fall),
                     blue_fall = (red_first ? second_fall : first_fall);
                if (blue_fall) {
                    continue;
                }
                if (red_fall) {
                    return step;
                } else {
                    int num = (red_first ? dist1 * 100 + dist2 : dist2 * 100 + dist1);
                    if (!visited[num]) {
                        visited[num] = true;
                        qu.emplace(num);
                    }
                }
            }
        }
        if (step == 10) {
            break;
        }
        step++;
    }
    return 11;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    board.resize(N);
    int red = 0;
    int blue = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == 'R') {
                red = i * 10 + j;
                ch = '.';
            } else if (ch == 'B') {
                blue = i * 10 + j;
                ch = '.';
            }
            board[i].emplace_back(ch);
        }
    }
    int ans = solve(red * 100 + blue);
    if (ans == 11) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
