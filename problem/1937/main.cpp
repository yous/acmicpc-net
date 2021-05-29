#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int forest[500][500];
int cache[500][500];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int solve(int y, int x) {
    if (cache[y][x] != 0) {
        return cache[y][x];
    }
    int num = forest[y][x];
    int ny, nx;
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || forest[ny][nx] <= num) {
            continue;
        }
        ans = max(ans, 1 + solve(ny, nx));
    }
    cache[y][x] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> forest[i][j];
        }
    }
    int ans = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << "\n";
    return 0;
}
