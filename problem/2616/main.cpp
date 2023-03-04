#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
short small_cap;

int solve(int small_num, int idx, vector<int>& prefix_sum, vector<vector<int>>& cache) {
    if (small_num == 3) {
        return 0;
    }
    if (idx + small_cap > N) {
        return 0;
    }
    auto& ans = cache[small_num][idx];
    if (ans >= 0) {
        return ans;
    }
    ans = max(prefix_sum[idx + small_cap] - prefix_sum[idx] + solve(small_num + 1, idx + small_cap, prefix_sum, cache), solve(small_num, idx + 1, prefix_sum, cache));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<int> prefix_sum(N + 1);
    int sum = 0;
    prefix_sum[0] = sum;
    for (int i = 0; i < N; i++) {
        short num;
        cin >> num;
        sum += num;
        prefix_sum[i + 1] = sum;
    }
    cin >> small_cap;
    vector<vector<int>> cache(3, vector<int>(N, -1));
    cout << solve(0, 0, prefix_sum, cache) << "\n";
    return 0;
}
