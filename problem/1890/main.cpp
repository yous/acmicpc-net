#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 4e18;
const int dy[] = {1, 0};
const int dx[] = {0, 1};
short N;

long long solve(int y, int x, vector<vector<short>>& field, vector<vector<long long>>& cache) {
    if (y >= N || x >= N) {
        return -INF;
    }
    if (y == N - 1 && x == N - 1) {
        return 1;
    }
    auto& ans = cache[y][x];
    if (ans != -1) {
        return ans;
    }
    if (field[y][x] == 0) {
        ans = -INF;
        return ans;
    }
    ans = 0;
    bool found = false;
    for (int i = 0; i < 2; i++) {
        int ny = y + dy[i] * field[y][x];
        int nx = x + dx[i] * field[y][x];
        if (ny >= N || nx >= N) {
            continue;
        }
        long long ret = solve(ny, nx, field, cache);
        if (ret < 0) {
            continue;
        }
        found = true;
        ans += ret;
    }
    if (!found) {
        ans = -INF;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<short>> field(N, vector<short>(N));
    for (auto& row : field) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<vector<long long>> cache(N, vector<long long>(N, -1));
    long long ans = solve(0, 0, field, cache);
    if (ans >= 0) {
        cout << ans << "\n";
    } else {
        cout << "0\n";
    }
    return 0;
}
