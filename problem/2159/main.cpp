#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;
const int dy[] = {-1, 1, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<pair<int, int>> customers(N);
    for (auto& [x, y] : customers) {
        cin >> x >> y;
    }
    vector<long long> dist(5, INF);
    auto [prev_x, prev_y] = customers[0];
    for (int dir = 0; dir < 5; dir++) {
        dist[dir] = abs(prev_x + dx[dir] - X) + abs(prev_y + dy[dir] - Y);
    }
    vector<long long> next_dist(5, INF);
    for (int i = 1; i < N; i++) {
        auto& [x, y] = customers[i];
        for (int dir = 0; dir < 5; dir++) {
            int sx = prev_x + dx[dir];
            int sy = prev_y + dy[dir];
            for (int ndir = 0; ndir < 5; ndir++) {
                next_dist[ndir] = min(next_dist[ndir], dist[dir] + abs(x + dx[ndir] - sx) + abs(y + dy[ndir] - sy));
            }
        }
        prev_x = x;
        prev_y = y;
        swap(dist, next_dist);
        fill(next_dist.begin(), next_dist.end(), INF);
    }
    long long ans = INF;
    for (int dir = 0; dir < 5; dir++) {
        ans = min(ans, dist[dir]);
    }
    cout << ans << "\n";
    return 0;
}
