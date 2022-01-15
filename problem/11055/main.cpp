#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<short> nums;
vector<int> cache;

int solve(int idx) {
    if (idx >= N) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = nums[idx];
    for (int i = idx + 1; i < N; i++) {
        if (nums[i] > nums[idx]) {
            ans = max(ans, nums[idx] + solve(i));
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
    cache.resize(N, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans << "\n";
    return 0;
}
