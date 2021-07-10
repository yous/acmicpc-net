#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M;
vector<vector<short>> paper;

int tetromino(int sy, int sx, vector<pair<int, int>>& points) {
    if (points.size() == 4) {
        return 0;
    }
    int ans = 0;
    int sz = points.size();
    for (int p = 0; p < sz; p++) {
        int y = points[p].first,
            x = points[p].second;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || find(points.begin(), points.end(), make_pair(ny, nx)) != points.end()) {
                continue;
            }
            points.emplace_back(ny, nx);
            ans = max(ans, paper[ny][nx] + tetromino(ny, nx, points));
            points.pop_back();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    paper.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            short num;
            cin >> num;
            paper[i].push_back(num);
        }
    }
    int ans = 0;
    vector<pair<int, int>> points;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            points.emplace_back(y, x);
            ans = max(ans, paper[y][x] + tetromino(y, x, points));
            points.pop_back();
        }
    }
    cout << ans << "\n";
    return 0;
}
