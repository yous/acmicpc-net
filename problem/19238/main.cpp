#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const short dy[] = {-1, 1, 0, 0};
const short dx[] = {0, 0, -1, 1};
short N, M;

short find_next(short y, short x, vector<vector<vector<short>>>& customers_dist, vector<bool>& visited) {
    short min_dist = N * N;
    short ans = -1;
    for (int i = 0; i < M; i++) {
        if (visited[i] || customers_dist[i][y][x] == -1) {
            continue;
        }
        if (customers_dist[i][y][x] < min_dist) {
            min_dist = customers_dist[i][y][x];
            ans = i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int fuel;
    cin >> N >> M >> fuel;
    vector<vector<bool>> field(N, vector<bool>(N));
    for (auto& row : field) {
        for (int i = 0; i < N; i++) {
            short num;
            cin >> num;
            row[i] = num == 1;
        }
    }
    short sy, sx;
    cin >> sy >> sx;
    sy--;
    sx--;
    vector<tuple<short, short, short, short>> customers(M);
    for (auto& [src_y, src_x, dst_y, dst_x] : customers) {
        cin >> src_y >> src_x >> dst_y >> dst_x;
        src_y--;
        src_x--;
        dst_y--;
        dst_x--;
    }
    sort(customers.begin(), customers.end());
    vector<vector<vector<short>>> customers_dist(M, vector<vector<short>>(N, vector<short>(N, -1)));
    for (int c = 0; c < M; c++) {
        auto& [src_y, src_x, dst_y, dst_x] = customers[c];
        auto& dist = customers_dist[c];
        vector<vector<bool>> visited(N, vector<bool>(N));
        queue<pair<short, short>> qu;
        visited[src_y][src_x] = true;
        dist[src_y][src_x] = 0;
        qu.emplace(src_y, src_x);
        short step = 1;
        while (!qu.empty()) {
            auto sz = qu.size();
            while (sz-- > 0) {
                auto [y, x] = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    short ny = y + dy[i];
                    short nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N || field[ny][nx] || visited[ny][nx]) {
                        continue;
                    }
                    visited[ny][nx] = true;
                    dist[ny][nx] = step;
                    qu.emplace(ny, nx);
                }
            }
            step++;
        }
    }
    vector<bool> visited(M);
    for (int i = 0; i < M; i++) {
        short c = find_next(sy, sx, customers_dist, visited);
        if (c < 0) {
            cout << "-1\n";
            return 0;
        }
        visited[c] = true;
        fuel -= customers_dist[c][sy][sx];
        if (fuel < 0) {
            cout << "-1\n";
            return 0;
        }
        auto& [src_y, src_x, dst_y, dst_x] = customers[c];
        short cost = customers_dist[c][dst_y][dst_x];
        if (cost < 0) {
            cout << "-1\n";
            return 0;
        }
        fuel -= cost;
        if (fuel < 0) {
            cout << "-1\n";
            return 0;
        }
        fuel += cost * 2;
        sy = dst_y;
        sx = dst_x;
    }
    cout << fuel << "\n";
    return 0;
}
