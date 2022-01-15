#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> nums;
vector<vector<int>> cache;

int solve(int idx, short num) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[idx][num];
    if (ans >= 0) {
        return ans;
    }
    ans = 0;
    for (int i = idx; i < N; i++) {
        if (nums[i] > num) {
            ans = max(ans, nums[i] + solve(i + 1, nums[i]));
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    nums.resize(N);
    for (short& num : nums) {
        cin >> num;
    }
    cache.resize(N, vector<int>(1001, -1));
    cout << solve(0, 0) << "\n";
    return 0;
}
