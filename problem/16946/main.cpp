#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M;
vector<string> field;
vector<vector<bool>> visited;

struct DisjointSet {
    vector<int> group;
    vector<int> counts;

    DisjointSet(int n) : group(n), counts(n) {
        for (int i = 0; i < n; i++) {
            group[i] = i;
            counts[i] = 1;
        }
    }

    int find(int n) {
        if (n == group[n]) {
            return n;
        }
        return group[n] = find(group[n]);
    }

    void merge(int p, int q) {
        int gp = find(p);
        int gq = find(q);
        if (gp != gq) {
            group[gp] = gq;
            counts[gq] += counts[gp];
        }
    }
};

void dfs(int y, int x, DisjointSet& ds) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || field[ny][nx] != '0' || visited[ny][nx]) {
            continue;
        }
        visited[ny][nx] = true;
        ds.merge(y * M + x, ny * M + nx);
        dfs(ny, nx, ds);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    field.resize(N);
    visited.resize(N, vector<bool>(M));
    DisjointSet ds(N * M);
    for (int i = 0; i < N; i++) {
        cin >> field[i];
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (field[y][x] == '0' && !visited[y][x]) {
                visited[y][x] = true;
                dfs(y, x, ds);
            }
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (field[y][x] == '1') {
                int cnt = 1;
                set<int> groups;
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || field[ny][nx] != '0') {
                        continue;
                    }
                    int group = ds.find(ny * M + nx);
                    if (groups.find(group) == groups.end()) {
                        cnt += ds.counts[group];
                        groups.insert(group);
                    }
                }
                cout << cnt % 10;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
    return 0;
}
