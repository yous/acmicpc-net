#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short R, C;
    int game_num = 1;
    while (cin >> R >> C) {
        if (R == 0 && C == 0) {
            break;
        }
        vector<string> game(R);
        pair<short, short> player;
        vector<pair<short, short>> targets;
        for (int y = 0; y < R; y++) {
            cin >> game[y];
            for (int x = 0; x < C; x++) {
                if (game[y][x] == '+' || game[y][x] == 'B' || game[y][x] == 'W') {
                    targets.emplace_back(y, x);
                }
                if (game[y][x] == 'w' || game[y][x] == 'W') {
                    player = {y, x};
                }
            }
        }
        string cmds;
        cin >> cmds;
        bool solved = false;
        for (auto cmd : cmds) {
            auto& [cy, cx] = player;
            int i = -1;
            if (cmd == 'U') {
                i = 0;
            } else if (cmd == 'D') {
                i = 1;
            } else if (cmd == 'L') {
                i = 2;
            } else {
                i = 3;
            }
            short ny = cy + dy[i];
            short nx = cx + dx[i];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || game[ny][nx] == '#') {
                continue;
            }
            if (game[ny][nx] == 'b' || game[ny][nx] == 'B') {
                short nny = ny + dy[i];
                short nnx = nx + dx[i];
                if (nny < 0 || nny >= R || nnx < 0 || nnx >= C || game[nny][nnx] == '#' || game[nny][nnx] == 'b' || game[nny][nnx] == 'B') {
                    continue;
                }
                if (game[nny][nnx] == '+') {
                    game[nny][nnx] = 'B';
                } else {
                    game[nny][nnx] = 'b';
                }
                if (game[ny][nx] == 'B') {
                    game[ny][nx] = '+';
                } else {
                    game[ny][nx] = '.';
                }
            }
            if (game[ny][nx] == '+') {
                game[ny][nx] = 'W';
            } else {
                game[ny][nx] = 'w';
            }
            if (game[cy][cx] == 'W') {
                game[cy][cx] = '+';
            } else {
                game[cy][cx] = '.';
            }
            cy = ny;
            cx = nx;
            solved = true;
            for (auto& [ty, tx] : targets) {
                if (game[ty][tx] != 'B') {
                    solved = false;
                    break;
                }
            }
            if (solved) {
                break;
            }
        }
        cout << "Game " << game_num;
        if (solved) {
            cout << ": complete\n";
        } else {
            cout << ": incomplete\n";
        }
        for (auto& row : game) {
            cout << row << "\n";
        }
        game_num++;
    }
    return 0;
}
