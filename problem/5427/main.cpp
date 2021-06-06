#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int T;
int W, H;
vector<string> bldg;
bool visited[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> W >> H;
        bldg.clear();
        memset(visited, 0, sizeof(visited));
        pair<int, int> start;
        queue<pair<int, int>> fire;
        for (int i = 0; i < H; i++) {
            string row;
            cin >> row;
            for (auto& ch : row) {
                switch (ch) {
                    case '@':
                        start = {i, &ch - &row[0]};
                        break;
                    case '*':
                        fire.push({i, &ch - &row[0]});
                        break;
                }
            }
            bldg.push_back(row);
        }
        queue<pair<int, int>> bfs;
        bfs.push(start);
        visited[start.first][start.second] = true;
        int step = 1;
        bool found = false;
        while (!bfs.empty()) {
            int sz = fire.size();
            while (sz-- > 0) {
                int y, x;
                tie(y, x) = fire.front();
                fire.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= H || nx < 0 || nx >= W || bldg[ny][nx] == '#' || bldg[ny][nx] == '*') {
                        continue;
                    }
                    bldg[ny][nx] = '*';
                    fire.push({ny, nx});
                }
            }
            sz = bfs.size();
            while (sz-- > 0) {
                int y, x;
                tie(y, x) = bfs.front();
                bfs.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                        cout << step << "\n";
                        found = true;
                        break;
                    }
                    if (bldg[ny][nx] == '*' || bldg[ny][nx] == '#' || visited[ny][nx]) {
                        continue;
                    }
                    visited[ny][nx] = true;
                    bfs.push({ny, nx});
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
            step++;
        }
        if (!found) {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
