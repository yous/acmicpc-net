#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
bool chess[10][10];
int cache[19][1 << 19];

int solve(int yx, bitset<19>& selected_nyx) {
    if (yx > N * 2 - 2) {
        return 0;
    }
    int& ans = cache[yx][selected_nyx.to_ulong()];
    if (ans > 0) {
        return ans;
    }
    ans = solve(yx + 1, selected_nyx);
    int y = min(yx, N - 1);
    int x = yx - y;
    while (x <= yx && x < N) {
        if (!chess[y][x] || selected_nyx[y + (N - 1 - x)]) {
            y--;
            x++;
            continue;
        }
        selected_nyx.flip(y + (N - 1 - x));
        ans = max(ans, 1 + solve(yx + 1, selected_nyx));
        selected_nyx.flip(y + (N - 1 - x));
        y--;
        x++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }
    bitset<19> selected_nyx(0);
    cout << solve(0, selected_nyx) << "\n";
    return 0;
}
