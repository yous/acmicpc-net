#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<short> nums(N);
    for (auto& num : nums) {
        cin >> num;
    }
    vector<int> cache(N, -INF);
    cache[0] = nums[0];
    int ans = cache[0];
    for (int i = 1; i < N; i++) {
        cache[i] = max(int(nums[i]), cache[i - 1] + nums[i]);
        ans = max(ans, cache[i]);
    }
    cout << ans << "\n";
    return 0;
}
