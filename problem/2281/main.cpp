#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
vector<int> nums;
vector<int> cache;

int solve(int idx) {
    if (idx < 0) {
        return 0;
    }
    int& ans = cache[idx];
    if (ans >= 0) {
        return ans;
    }
    ans = INF;
    int width = nums[idx];
    while (width <= M) {
        ans = min(ans, (M - width) * (M - width) + solve(idx - 1));
        if (idx == 0) {
            break;
        }
        width += nums[idx - 1] + 1;
        idx--;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    nums.resize(N);
    cache.resize(N, -1);
    for (int& num : nums) {
        cin >> num;
    }
    int idx = N - 1;
    int width = nums[idx];
    int ans = INF;
    while (width <= M) {
        ans = min(ans, solve(idx - 1));
        if (idx == 0) {
            break;
        }
        width += nums[idx - 1] + 1;
        idx--;
    }
    cout << ans << "\n";
    return 0;
}
