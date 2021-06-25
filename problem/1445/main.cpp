#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 30000;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M;
vector<string> field;
pair<short, short> dist[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    pair<short, short> start;
    pair<short, short> finish;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            if (row[j] == 'S') {
                start = {i, j};
            } else if (row[j] == 'F') {
                finish = {i, j};
            }
        }
        field.push_back(row);
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (field[y][x] == 'g') {
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || field[ny][nx] != '.') {
                        continue;
                    }
                    field[ny][nx] = 'z';
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + M, make_pair<short, short>(INF, INF));
     }
    queue<tuple<short, short, short, short>> qu;
    dist[start.first][start.second] = {0, 0};
    qu.emplace(start.first, start.second, 0, 0);
    while (!qu.empty()) {
        auto& e = qu.front();
        short y, x, g, z;
        tie(y, x, g, z) = e;
        qu.pop();
        if (y == finish.first && x == finish.second) {
            continue;
        }
        if (dist[y][x].first < g || (dist[y][x].first == g && dist[y][x].second < z)) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            short ny = y + dy[i];
            short nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
                continue;
            }
            auto& p = dist[ny][nx];
            if (field[ny][nx] == 'g') {
                if (g + 1 < p.first || (g + 1 == p.first && z < p.second)) {
                    p.first = g + 1;
                    p.second = z;
                    qu.emplace(ny, nx, g + 1, z);
                }
            } else if (field[ny][nx] == 'z') {
                if (g < p.first || (g == p.first && z + 1 < p.second)) {
                    p.first = g;
                    p.second = z + 1;
                    qu.emplace(ny, nx, g, z + 1);
                }
            } else {
                if (g < p.first || (g == p.first && z < p.second)) {
                    p.first = g;
                    p.second = z;
                    qu.emplace(ny, nx, g, z);
                }
            }
        }
    }
    auto& ans = dist[finish.first][finish.second];
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
