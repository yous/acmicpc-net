#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<bool>> room;
vector<vector<int>> cache[3];

int solve(int y, int x, int rotate) {
    if (y == N - 1 && x == N - 1) {
        return 1;
    }
    int& ans = cache[rotate][y][x];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    switch (rotate) {
        case 0:
            if (x < N - 1 && !room[y][x + 1]) {
                ans += solve(y, x + 1, 0);
                if (y < N - 1 && !room[y + 1][x] && !room[y + 1][x + 1]) {
                    ans += solve(y + 1, x + 1, 1);
                }
            }
            break;
        case 1: {
            bool can_x = (x < N - 1) && !room[y][x + 1];
            bool can_y = (y < N - 1) && !room[y + 1][x];
            if (can_x) {
                ans += solve(y, x + 1, 0);
            }
            if (can_y) {
                ans += solve(y + 1, x, 2);
            }
            if (can_x && can_y && !room[y + 1][x + 1]) {
                ans += solve(y + 1, x + 1, 1);
            }
            break;
        }
        case 2:
            if (y < N - 1 && !room[y + 1][x]) {
                ans += solve(y + 1, x, 2);
                if (x < N - 1 && !room[y][x + 1] && !room[y + 1][x + 1]) {
                    ans += solve(y + 1, x + 1, 1);
                }
            }
            break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    room.resize(N, vector<bool>(N));
    for (int i = 0; i < 3; i++) {
        cache[i].resize(N, vector<int>(N, -1));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool wall;
            cin >> wall;
            room[i][j] = wall;
        }
    }
    cout << solve(0, 1, 0) << "\n";
    return 0;
}
