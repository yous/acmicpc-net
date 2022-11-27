#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        short H, W, O, F, Xs, Ys, Xe, Ye;
        cin >> H >> W >> O >> F >> Ys >> Xs >> Ye >> Xe;
        Ys--;
        Xs--;
        Ye--;
        Xe--;
        vector<vector<short>> field(H, vector<short>(W));
        for (int i = 0; i < O; i++) {
            short X, Y, L;
            cin >> Y >> X >> L;
            field[Y - 1][X - 1] = L;
        }
        queue<tuple<short, short, short>> qu;
        vector<vector<bool>> visited(H, vector<bool>(W));
        qu.emplace(Ys, Xs, F);
        visited[Ys][Xs] = true;
        bool reach = false;
        while (!qu.empty()) {
            auto [y, x, f] = qu.front();
            qu.pop();
            if (y == Ye && x == Xe) {
                reach = true;
                break;
            }
            if (f == 0) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx]) {
                    continue;
                }
                if (field[ny][nx] <= field[y][x] || f >= field[ny][nx] - field[y][x]) {
                    visited[ny][nx] = true;
                    qu.emplace(ny, nx, f - 1);
                }
            }
        }
        if (reach) {
            cout << "잘했어!!\n";
        } else {
            cout << "인성 문제있어??\n";
        }
    }
    return 0;
}
