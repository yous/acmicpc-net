#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<int> nums(5);

int solve(int idx, int cnt, int mul) {
    if (cnt == 3) {
        return mul;
    }
    if (idx == 5) {
        return INF;
    }
    return min(solve(idx + 1, cnt + 1, lcm(mul, nums[idx])), solve(idx + 1, cnt, mul));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int& num : nums) {
        cin >> num;
    }
    cout << solve(0, 0, 1) << "\n";
    return 0;
}
