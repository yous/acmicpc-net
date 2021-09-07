#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};
short R, C, M;
vector<vector<short>> sea;
vector<vector<short>> next_sea;
vector<tuple<short, short, short, short, short>> sharks;
vector<bool> dead;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> M;
    sea.resize(R, vector<short>(C));
    dead.resize(M);
    for (int i = 0; i < M; i++) {
        short r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sea[r - 1][c - 1] = i + 1;
        if (d <= 2) {
            s %= (R - 1) * 2;
        } else {
            s %= (C - 1) * 2;
        }
        sharks.emplace_back(r - 1, c - 1, s, d - 1, z);
    }
    int ans = 0;
    for (int x = 0; x < C; x++) {
        for (int y = 0; y < R; y++) {
            int shark = sea[y][x] - 1;
            if (shark == -1 || dead[shark]) {
                continue;
            }
            ans += get<4>(sharks[shark]);
            dead[shark] = true;
            break;
        }
        if (x == C - 1) {
            break;
        }
        next_sea.clear();
        next_sea.resize(R, vector<short>(C));
        for (int i = 0; i < M; i++) {
            if (dead[i]) {
                continue;
            }
            auto& [r, c, s, d, z] = sharks[i];
            int ny = r + dy[d] * s;
            int nx = c + dx[d] * s;
            while (ny < 0 || ny >= R) {
                d ^= 1;
                if (ny < 0) {
                    ny = -ny;
                } else {
                    ny = R - 1 - (ny - (R - 1));
                }
            }
            while (nx < 0 || nx >= C) {
                d ^= 1;
                if (nx < 0) {
                    nx = -nx;
                } else {
                    nx = C - 1 - (nx - (C - 1));
                }
            }
            int prev_shark = next_sea[ny][nx];
            if (prev_shark > 0) {
                if (z > get<4>(sharks[prev_shark - 1])) {
                    dead[prev_shark - 1] = true;
                } else {
                    dead[i] = true;
                    continue;
                }
            }
            next_sea[ny][nx] = i + 1;
            r = ny;
            c = nx;
        }
        swap(sea, next_sea);
    }
    cout << ans << "\n";
    return 0;
}
