#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;
int cache[1000][1001];

int solve(int start, int limit) {
    if (start == N - 1) {
        return (nums[start] > limit) ? 1 : 0;
    }
    int& ans = cache[start][limit];
    if (ans >= 0) {
        return ans;
    }
    ans = solve(start + 1, limit);
    if (nums[start] > limit) {
        ans = max(ans, 1 + solve(start + 1, nums[start]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << solve(0, 0) << "\n";
    return 0;
}
