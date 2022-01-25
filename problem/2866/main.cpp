#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short R, C;
    cin >> R >> C;
    vector<string> table(R);
    for (string& row : table) {
        cin >> row;
    }
    vector<string> cols(C);
    for (int y = R - 1; y >= 0; y--) {
        for (int x = 0; x < C; x++) {
            cols[x].push_back(table[y][x]);
        }
    }
    sort(cols.begin(), cols.end());
    int ans = R - 1;
    for (int i = 0; i < C - 1; i++) {
        int idx = 0;
        while (cols[i][idx] == cols[i + 1][idx]) {
            idx++;
        }
        ans = min(ans, R - 1 - idx);
    }
    cout << ans << "\n";
    return 0;
}
