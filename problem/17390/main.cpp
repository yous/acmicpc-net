#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<int> nums;
vector<int> prefix_sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    nums.resize(N);
    prefix_sum.resize(N + 1);
    for (int& num : nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end());
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << prefix_sum[R] - prefix_sum[L - 1] << "\n";
    }
    return 0;
}
