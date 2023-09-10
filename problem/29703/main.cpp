#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<string> town(N);
    short sy = -1;
    short sx = -1;
    short hy = -1;
    short hx = -1;
    vector<pair<short, short>> fishes;
    for (int y = 0; y < N; y++) {
        cin >> town[y];
        for (int x = 0; x < M; x++) {
            if (town[y][x] == 'S') {
                sy = y;
                sx = x;
            } else if (town[y][x] == 'H') {
                hy = y;
                hx = x;
            } else if (town[y][x] == 'F') {
                fishes.emplace_back(y, x);
            }
        }
    }
    vector<vector<int>> dist(N, vector<int>(M, INF));
    queue<pair<short, short>> qu;
    qu.emplace(sy, sx);
    dist[sy][sx] = 0;
    int step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || dist[ny][nx] < INF || town[ny][nx] == 'D') {
                    continue;
                }
                dist[ny][nx] = step;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
    vector<vector<int>> hdist(N, vector<int>(M, INF));
    qu.emplace(hy, hx);
    hdist[hy][hx] = 0;
    step = 1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz-- > 0) {
            auto [y, x] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                short ny = y + dy[i];
                short nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || hdist[ny][nx] < INF || town[ny][nx] == 'D') {
                    continue;
                }
                hdist[ny][nx] = step;
                qu.emplace(ny, nx);
            }
        }
        step++;
    }
    int ans = INF;
    for (auto [fy, fx] : fishes) {
        if (dist[fy][fx] == INF || hdist[fy][fx] == INF) {
            continue;
        }
        ans = min(ans, dist[fy][fx] + hdist[fy][fx]);
    }
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
