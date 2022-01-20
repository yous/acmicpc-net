#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;
vector<vector<int>> cache;

int solve(int idx, int prev_idx) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[idx][prev_idx];
    if (ans > 0) {
        return ans;
    }
    ans = 1;
    int diff = nums[idx] - nums[prev_idx];
    int next_idx = lower_bound(next(nums.begin(), idx + 1), nums.end(), nums[idx] + diff) - nums.begin();
    if (next_idx < N && nums[next_idx] == nums[idx] + diff) {
        ans = 1 + solve(next_idx, idx);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    nums.resize(N);
    for (int& num : nums) {
        cin >> num;
    }
    if (N == 1) {
        cout << "1\n";
        return 0;
    }
    cache.resize(N);
    for (int i = 1; i < N; i++) {
        cache[i].resize(i);
    }
    sort(nums.begin(), nums.end());
    int ans = 2;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ans = max(ans, 1 + solve(j, i));
        }
    }
    cout << ans << "\n";
    return 0;
}
