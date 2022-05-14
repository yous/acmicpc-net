#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};
short N, M;
vector<vector<short>> jobs;
vector<vector<short>> times;
vector<vector<vector<int>>> cache;

int solve(int y, int x, int rem) {
    int& ans = cache[y][x][rem];
    if (ans >= -1) {
        return ans;
    }
    ans = -1;
    if (y == N - 1 && x == M - 1) {
        ans = 0;
        return ans;
    }
    if (rem == 0) {
        return ans;
    }
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= N || nx >= M) {
            continue;
        }
        int ret = solve(ny, nx, rem - 1);
        if (ret >= 0) {
            ans = max(ans, ret);
        }
        if (times[ny][nx] <= rem - 1) {
            ret = solve(ny, nx, rem - 1 - times[ny][nx]);
            if (ret >= 0) {
                ans = max(ans, jobs[ny][nx] + ret);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> N >> M >> T;
    jobs.resize(N, vector<short>(M));
    for (auto& row : jobs) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    times.resize(N, vector<short>(M));
    for (auto& row : times) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    cache.resize(N, vector<vector<int>>(M, vector<int>(T + 1, -2)));
    cout << solve(0, 0, T) << "\n";
    return 0;
}
