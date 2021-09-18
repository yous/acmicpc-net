#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int T;
int H, W;
vector<string> building;
vector<bool> keys(26);
vector<vector<short>> doors(26);
vector<bool> visited;
queue<short> qu;

bool pass(int y, int x) {
    char ch = building[y][x];
    if (ch == '*') {
        return false;
    }
    if (ch >= 'A' && ch <= 'Z') {
        if (keys[ch - 'A']) {
            return true;
        } else {
            doors[ch - 'A'].emplace_back(y * W + x);
            return false;
        }
    } else if (ch >= 'a' && ch <= 'z') {
        if (keys[ch - 'a']) {
            return true;
        } else {
            keys[ch - 'a'] = true;
            for (int idx : doors[ch - 'a']) {
                if (!visited[idx]) {
                    visited[idx] = true;
                    qu.emplace(idx);
                }
            }
            doors[ch - 'a'].clear();
            return true;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> H >> W;
        building.clear();
        building.resize(H);
        fill(keys.begin(), keys.end(), false);
        fill(doors.begin(), doors.end(), vector<short>());
        visited.clear();
        visited.resize(H * W);
        for (int i = 0; i < H; i++) {
            cin >> building[i];
        }
        string s;
        cin >> s;
        for (char k : s) {
            if (k == '0') {
                break;
            }
            keys[k - 'a'] = true;
        }
        for (int j = 0; j < W; j++) {
            if (pass(0, j)) {
                visited[j] = true;
                qu.emplace(j);
            }
            if (pass(H - 1, j)) {
                visited[(H - 1) * W + j] = true;
                qu.emplace((H - 1) * W + j);
            }
        }
        for (int i = 1; i < H - 1; i++) {
            if (pass(i, 0)) {
                visited[i * W] = true;
                qu.emplace(i * W);
            }
            if (pass(i, W - 1)) {
                visited[i * W + W - 1] = true;
                qu.emplace(i * W + W - 1);
            }
        }
        int ans = 0;
        while (!qu.empty()) {
            short yx = qu.front();
            qu.pop();
            int y = yx / W,
                x = yx % W;
            if (building[y][x] == '$') {
                ans++;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny * W + nx]) {
                    continue;
                }
                if (pass(ny, nx)) {
                    visited[ny * W + nx] = true;
                    qu.emplace(ny * W + nx);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
