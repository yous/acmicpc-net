#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int y, int x, int sz, vector<vector<int>>& chairs) {
    if (sz == 1) {
        return chairs[y][x];
    }
    vector<int> ans;
    ans.emplace_back(solve(y, x, sz / 2, chairs));
    ans.emplace_back(solve(y, x + sz / 2, sz / 2, chairs));
    ans.emplace_back(solve(y + sz / 2, x, sz / 2, chairs));
    ans.emplace_back(solve(y + sz / 2, x + sz / 2, sz / 2, chairs));
    sort(ans.begin(), ans.end());
    return ans[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<vector<int>> chairs(N, vector<int>(N));
    for (auto& row : chairs) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    cout << solve(0, 0, N, chairs) << "\n";
    return 0;
}
