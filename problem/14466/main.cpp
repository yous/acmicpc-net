#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};
short N, K, R;

struct DisjointSet {
    short N;
    vector<short> group;
    vector<short> cnt;

    DisjointSet(short n) : N(n), group(n), cnt(n, 1) {
        for (int i = 0; i < N; i++) {
            group[i] = i;
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
            group[gp] = gq;
            cnt[gq] += cnt[gp];
            return true;
        }
        return false;
    }
};

void bfs(short idx, DisjointSet& ds, vector<vector<bool>>& visited, vector<pair<short, short>>& cows, vector<vector<short>>& cow_num, vector<vector<short>>& graph) {
    queue<pair<short, short>> qu;
    qu.emplace(cows[idx]);
    while (!qu.empty()) {
        auto [y, x] = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++) {
            if ((graph[y][x] & (1 << i)) != 0) {
                continue;
            }
            short ny = y + dy[i];
            short nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = true;
            if (cow_num[ny][nx] != -1) {
                ds.merge(idx, cow_num[ny][nx]);
            }
            qu.emplace(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> R;
    vector<vector<short>> graph(N, vector<short>(N));
    for (int i = 0; i < R; i++) {
        short r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        for (int j = 0; j < 4; j++) {
            short ny = r1 + dy[j];
            short nx = c1 + dx[j];
            if (ny == r2 && nx == c2) {
                graph[r1][c1] |= (1 << j);
                break;
            }
        }
        for (int j = 0; j < 4; j++) {
            short ny = r2 + dy[j];
            short nx = c2 + dx[j];
            if (ny == r1 && nx == c1) {
                graph[r2][c2] |= (1 << j);
                break;
            }
        }
    }
    vector<pair<short, short>> cows(K);
    vector<vector<short>> cow_num(N, vector<short>(N, -1));
    for (int i = 0; i < K; i++) {
        auto& [r, c] = cows[i];
        cin >> r >> c;
        r--;
        c--;
        cow_num[r][c] = i;
    }
    DisjointSet ds(K);
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i = 0; i < K; i++) {
        auto& cow = cows[i];
        if (visited[cow.first][cow.second]) {
            continue;
        }
        visited[cow.first][cow.second] = true;
        bfs(i, ds, visited, cows, cow_num, graph);
    }
    int ans = K * (K - 1) / 2;
    vector<bool> group_visited(N);
    for (int i = 0; i < K; i++) {
        short g = ds.find(i);
        if (group_visited[g]) {
            continue;
        }
        group_visited[g] = true;
        short g_cnt = ds.cnt[g];
        ans -= g_cnt * (g_cnt - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
