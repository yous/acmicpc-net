#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<short>> triangle;
vector<vector<int>> cache;

int solve(int row, int idx) {
    if (row == N) {
        return 0;
    }
    int& ans = cache[row][idx];
    if (ans >= 0) {
        return ans;
    }
    ans = triangle[row][idx] + max(solve(row + 1, idx), solve(row + 1, idx + 1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    triangle.resize(N);
    cache.resize(N);
    for (int row = 1; row <= N; row++) {
        cache[row - 1].resize(row, -1);
        for (int i = 0; i < row; i++) {
            short num;
            cin >> num;
            triangle[row - 1].push_back(num);
        }
    }
    cout << solve(0, 0) << "\n";
    return 0;
}
