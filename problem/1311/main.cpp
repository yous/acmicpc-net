#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

short N;

int solve(int idx, int visited, vector<vector<int>>& cache, vector<vector<short>>& D) {
    if (idx == N) {
        return 0;
    }
    auto& ans = cache[idx][visited];
    if (ans != INF) {
        return ans;
    }
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) {
            continue;
        }
        ans = min(ans, D[idx][i] + solve(idx + 1, visited | (1 << i), cache, D));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<short>> D(N, vector<short>(N));
    for (auto& row : D) {
        for (auto& num : row) {
            cin >> num;
        }
    }
    vector<vector<int>> cache(N, vector<int>(1 << N, INF));
    cout << solve(0, 0, cache, D) << "\n";
    return 0;
}
