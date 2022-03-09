#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short INF = 30000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
short N, M;

struct DisjointSet {
    short N;
    vector<short> group;
    vector<short> cnt;

    DisjointSet(short n) : N(n), group(n), cnt(n) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
            cnt[i] = 1;
        }
    }

    short find(short n) {
        short g = group[n];
        if (g == n) {
            return g;
        }
        return group[n] = find(g);
    }

    bool merge(short p, short q) {
        short gp = find(p);
        short gq = find(q);
        if (gp != gq) {
            group[gq] = gp;
            cnt[gp] += cnt[gq];
            return true;
        }
        return false;
    }
};

void dfs(vector<vector<short>>& sea, int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || sea[ny][nx] >= 0) {
            continue;
        }
        sea[ny][nx] = sea[y][x];
        dfs(sea, ny, nx);
    }
}

void dfs_dist(vector<vector<short>>& sea, int y, int x, vector<vector<short>>& dist, vector<vector<bool>>& visited) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) {
            continue;
        }
        if (sea[ny][nx] == 0) {
            if (dy[i] != 0) {
                int ny2 = ny + dy[i];
                while (ny2 >= 0 && ny2 < N && sea[ny2][nx] == 0) {
                    ny2 += dy[i];
                }
                if (ny2 >= 0 && ny2 < N && abs(ny2 - y) - 1 >= 2) {
                    int u = sea[y][x] - 1;
                    int v = sea[ny2][nx] - 1;
                    if (u > v) {
                        swap(u, v);
                    }
                    dist[u][v] = min(dist[u][v], short(abs(ny2 - y) - 1));
                }
            } else {
                int nx2 = nx + dx[i];
                while (nx2 >= 0 && nx2 < M && sea[ny][nx2] == 0) {
                    nx2 += dx[i];
                }
                if (nx2 >= 0 && nx2 < M && abs(nx2 - x) - 1 >= 2) {
                    int u = sea[y][x] - 1;
                    int v = sea[ny][nx2] - 1;
                    if (u > v) {
                        swap(u, v);
                    }
                    dist[u][v] = min(dist[u][v], short(abs(nx2 - x) - 1));
                }
            }
            continue;
        }
        visited[ny][nx] = true;
        dfs_dist(sea, ny, nx, dist, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<vector<short>> sea(N, vector<short>(M));
    for (auto& row : sea) {
        for (auto& num : row) {
            cin >> num;
            num = -num;
        }
    }
    int island = 0;
    vector<pair<int, int>> islands;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (sea[i][j] < 0) {
                island++;
                sea[i][j] = island;
                islands.emplace_back(i, j);
                dfs(sea, i, j);
            }
        }
    }
    vector<vector<short>> dist(island, vector<short>(island, INF));
    vector<vector<bool>> visited(N, vector<bool>(M));
    for (auto [y, x] : islands) {
        visited[y][x] = true;
        dfs_dist(sea, y, x, dist, visited);
    }
    priority_queue<tuple<short, int, int>> pq;
    for (int i = 0; i < island; i++) {
        for (int j = i + 1; j < island; j++) {
            if (dist[i][j] == INF) {
                continue;
            }
            pq.emplace(-dist[i][j], i, j);
        }
    }
    DisjointSet ds(island);
    short ans = 0;
    while (!pq.empty()) {
        auto [d, u, v] = pq.top();
        d = -d;
        pq.pop();
        if (ds.merge(u, v)) {
            ans += d;
        }
    }
    if (ds.cnt[ds.find(0)] == island) {
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
