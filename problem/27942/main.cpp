#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<int>> sum_x(N, vector<int>(N + 1));
    vector<vector<int>> sum_y(N, vector<int>(N + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            short num;
            cin >> num;
            sum_x[i][j + 1] = sum_x[i][j] + num;
            sum_y[j][i + 1] = sum_y[j][i] + num;
        }
    }
    pair<short, short> left_top = {N / 2 - 1, N / 2 - 1};
    short width = 2;
    short height = 2;
    int sum = 0;
    string ans;
    while (true) {
        int dir = -1;
        int next_sum = -1;
        for (int i = 0; i < 4; i++) {
            if (dy[i] != 0) {
                int ny = left_top.first + (dy[i] < 0 ? dy[i] : height);
                if (ny < 0 || ny >= N) {
                    continue;
                }
                int dir_sum = sum_x[ny][left_top.second + width] - sum_x[ny][left_top.second];
                if (dir_sum > 0 && next_sum < dir_sum) {
                    next_sum = dir_sum;
                    dir = i;
                }
            } else {
                int nx = left_top.second + (dx[i] < 0 ? dx[i] : width);
                if (nx < 0 || nx >= N) {
                    continue;
                }
                int dir_sum = sum_y[nx][left_top.first + height] - sum_y[nx][left_top.first];
                if (dir_sum > 0 && next_sum < dir_sum) {
                    next_sum = dir_sum;
                    dir = i;
                }
            }
        }
        if (dir == -1) {
            break;
        }
        if (dy[dir] < 0) {
            left_top.first += dy[dir];
        }
        if (dx[dir] < 0) {
            left_top.second += dx[dir];
        }
        width += abs(dx[dir]);
        height += abs(dy[dir]);
        sum += next_sum;
        ans += "UDLR"[dir];
    }
    cout << sum << "\n";
    cout << ans << "\n";
    return 0;
}
