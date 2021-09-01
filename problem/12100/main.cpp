#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N;
vector<vector<unsigned short>> board;

void step(vector<vector<unsigned short>>& board, vector<vector<unsigned short>>& res, int dy, int dx) {
    if (dy != 0) {
        for (int j = 0; j < N; j++) {
            int dest_i = (dy == -1 ? 0 : N - 1);
            int i = dest_i;
            unsigned short cur = board[i][j];
            i -= dy;
            while (0 <= i && i < N) {
                if (board[i][j] == 0) {
                    i -= dy;
                    continue;
                }
                if (cur == 0) {
                    cur = board[i][j];
                } else if (board[i][j] == cur) {
                    res[dest_i][j] = cur * 2;
                    dest_i -= dy;
                    cur = 0;
                } else {
                    res[dest_i][j] = cur;
                    dest_i -= dy;
                    cur = board[i][j];
                }
                i -= dy;
            }
            if (cur != 0) {
                res[dest_i][j] = cur;
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            int dest_j = (dx == -1 ? 0 : N - 1);
            int j = dest_j;
            unsigned short cur = board[i][j];
            j -= dx;
            while (0 <= j && j < N) {
                if (board[i][j] == 0) {
                    j -= dx;
                    continue;
                }
                if (cur == 0) {
                    cur = board[i][j];
                } else if (board[i][j] == cur) {
                    res[i][dest_j] = cur * 2;
                    dest_j -= dx;
                    cur = 0;
                } else {
                    res[i][dest_j] = cur;
                    dest_j -= dx;
                    cur = board[i][j];
                }
                j -= dx;
            }
            if (cur != 0) {
                res[i][dest_j] = cur;
            }
        }
    }
}

unsigned short solve(int cnt, vector<vector<unsigned short>>& board) {
    if (cnt == 5) {
        unsigned short ret = 0;
        for (int i = 0; i < N; i++) {
            ret = max(ret, *max_element(board[i].begin(), board[i].end()));
        }
        return ret;
    }
    unsigned short ret = 0;
    for (int i = 0; i < 4; i++) {
        vector<vector<unsigned short>> tmp(N, vector<unsigned short>(N));
        step(board, tmp, dy[i], dx[i]);
        ret = max(ret, solve(cnt + 1, tmp));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    board.resize(N, vector<unsigned short>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    cout << solve(0, board) << "\n";
    return 0;
}
