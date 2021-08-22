#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x7FFFFFFF;
int N;
vector<int> nums;
vector<vector<int>> cache;

int solve(int st, int ed) {
    auto& ans = cache[st][ed];
    if (ans >= 0) {
        return ans;
    }
    if (st == ed) {
        ans = 0;
        return ans;
    }
    if (st + 1 == ed) {
        ans = nums[st] * nums[st + 1] * nums[st + 2];
        return ans;
    }
    ans = INF;
    for (int div = st; div < ed; div++) {
        int left_prod = solve(st, div);
        int right_prod = solve(div + 1, ed);
        ans = min(ans, left_prod + nums[st] * nums[div + 1] * nums[ed + 1] + right_prod);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cache.resize(N + 1, vector<int>(N + 1, -1));
    int a, b;
    cin >> a >> b;
    nums.push_back(a);
    nums.push_back(b);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        nums.push_back(b);
    }
    cout << solve(0, N - 1) << "\n";
    return 0;
}
