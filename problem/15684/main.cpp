#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<bool>> ladders;

int solve(int row, int col, int used) {
    if (used > 3) {
        return 4;
    }
    if (col >= N) {
        row++;
        col = 1;
    }
    if (used == 3 || row >= H) {
        for (int i = 1; i <= N; i++) {
            int start = i;
            for (int y = 0; y < H; y++) {
                if (ladders[y][start - 1]) {
                    start--;
                } else if (ladders[y][start]) {
                    start++;
                }
            }
            if (start != i) {
                return 4;
            }
        }
        return used;
    }
    int ans = 4;
    if (!ladders[row][col - 1] && !ladders[row][col] && !ladders[row][col + 1]) {
        ladders[row][col] = true;
        ans = min(ans, solve(row, col + 2, used + 1));
        ladders[row][col] = false;
    }
    ans = min(ans, solve(row, col + 1, used));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> H;
    ladders.resize(H, vector<bool>(N + 1));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladders[a - 1][b] = true;
    }
    int ans = solve(0, 1, 0);
    if (ans == 4) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}
