#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const short dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int T;
int L;
bool visited[300][300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> L;
        memset(visited, 0, sizeof(visited));
        short src_y, src_x;
        short dest_y, dest_x;
        cin >> src_y >> src_x >> dest_y >> dest_x;
        queue<pair<short, short>> qu;
        qu.push({src_y, src_x});
        visited[src_y][src_x] = true;
        int step = 0;
        bool found = false;
        while (!found && !qu.empty()) {
            int sz = qu.size();
            while (sz-- > 0) {
                auto& point = qu.front();
                qu.pop();
                short y = point.first;
                short x = point.second;
                if (y == dest_y && x == dest_x) {
                    found = true;
                    cout << step << "\n";
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    short ny = y + dy[i];
                    short nx = x + dx[i];
                    if (ny < 0 || ny >= L || nx < 0 || nx >= L || visited[ny][nx]) {
                        continue;
                    }
                    qu.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
            step++;
        }
    }
    return 0;
}
