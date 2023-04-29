#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

short solve(int y, int x, int sz, vector<vector<short>>& matrix) {
    if (sz == 1) {
        return matrix[y][x];
    }
    array<short, 4> ans = {
        solve(y, x, sz / 2, matrix),
        solve(y, x + sz / 2, sz / 2, matrix),
        solve(y + sz / 2, x, sz / 2, matrix),
        solve(y + sz / 2, x + sz / 2, sz / 2, matrix)
    };
    nth_element(ans.begin(), &ans[2], ans.end());
    return ans[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<short>> matrix(N, vector<short>(N));
    for (auto& row : matrix) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    cout << solve(0, 0, N, matrix) << "\n";
    return 0;
}
