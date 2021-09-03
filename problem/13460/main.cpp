#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dy[] = {-100, 100, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<vector<char>> board;

bool tilt(int& ball, int dir) {
    while (board[ball / 100][ball % 100] == '.') {
        ball += dy[dir];
        ball += dx[dir];
    }
    if (board[ball / 100][ball % 100] == 'O') {
        return true;
    } else {
        ball -= dy[dir];
        ball -= dx[dir];
        return false;
    }
}

int solve(int start_red, int start_blue) {
    queue<tuple<int, int, int>> qu;
    qu.emplace(start_red, start_blue, -1);
    int step = 1;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [red, blue, dir] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                if (i == dir) {
                    continue;
                }
                bool red_first;
                if (dy[i] != 0) {
                    red_first = (red / 100 * dy[i] > blue / 100 * dy[i]);
                } else {
                    red_first = (red % 100 * dx[i] > blue % 100 * dx[i]);
                }
                bool first_fall = false,
                     second_fall = false;
                int dist1 = (red_first ? red : blue);
                first_fall = tilt(dist1, i);
                if (!first_fall) {
                    board[dist1 / 100][dist1 % 100] = '#';
                }
                int dist2 = (red_first ? blue : red);
                second_fall = tilt(dist2, i);
                if (!first_fall) {
                    board[dist1 / 100][dist1 % 100] = '.';
                }
                bool red_fall = (red_first ? first_fall : second_fall),
                     blue_fall = (red_first ? second_fall : first_fall);
                if (blue_fall) {
                    continue;
                }
                if (red_fall) {
                    return step;
                } else {
                    qu.emplace((red_first ? dist1 : dist2), (red_first ? dist2 : dist1), i);
                }
            }
        }
        step++;
        if (step > 10) {
            break;
        }
    }
    return step;
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
                red = i * 100 + j;
                ch = '.';
            } else if (ch == 'B') {
                blue = i * 100 + j;
                ch = '.';
            }
            board[i].emplace_back(ch);
        }
    }
    int ans = solve(red, blue);
    if (ans == 11) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
