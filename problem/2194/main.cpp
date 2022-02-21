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
    short N, M, A, B;
    int K;
    cin >> N >> M >> A >> B >> K;
    vector<vector<bool>> field(N, vector<bool>(M));
    for (int i = 0; i < K; i++) {
        short y, x;
        cin >> y >> x;
        y--;
        x--;
        field[y][x] = true;
    }
    pair<short, short> st, ed;
    cin >> st.first >> st.second >> ed.first >> ed.second;
    st.first--;
    st.second--;
    ed.first--;
    ed.second--;
    vector<vector<bool>> visited(N, vector<bool>(M));
    queue<pair<short, short>> qu;
    visited[st.first][st.second] = true;
    qu.emplace(st);
    int step = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            if (y == ed.first && x == ed.second) {
                cout << step << "\n";
                return 0;
            }
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny + A - 1 >= N || nx < 0 || nx + B - 1 >= M || visited[ny][nx]) {
                    continue;
                }
                bool can_move = true;
                if (dy[i] != 0) {
                    short chk_y = (dy[i] > 0 ? ny + A - 1 : ny);
                    for (int j = 0; j < B; j++) {
                        if (field[chk_y][x + j]) {
                            can_move = false;
                            break;
                        }
                    }
                } else {
                    short chk_x = (dx[i] > 0 ? nx + B - 1 : nx);
                    for (int j = 0; j < A; j++) {
                        if (field[y + j][chk_x]) {
                            can_move = false;
                            break;
                        }
                    }
                }
                if (!can_move) {
                    continue;
                }
                visited[ny][nx] = true;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
    cout << "-1\n";
    return 0;
}
