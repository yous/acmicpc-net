#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    vector<int> nums(N);
    for (int& num : nums) {
        cin >> num;
    }
    vector<int> cnt(1000001);
    vector<tuple<int, int, int>> queries(T);
    int idx = 0;
    for (auto& [l, r, i] : queries) {
        cin >> l >> r;
        l--;
        r--;
        i = idx;
        idx++;
    }
    int sqrt_sz = sqrt(1000000);
    sort(queries.begin(), queries.end(), [&](auto& lhs, auto& rhs) {
        int chunk1 = get<1>(lhs) / sqrt_sz;
        int chunk2 = get<1>(rhs) / sqrt_sz;
        if (chunk1 != chunk2) {
            return chunk1 < chunk2;
        }
        return get<0>(lhs) < get<0>(rhs);
    });
    vector<long long> ans(T);
    long long sum = 0;
    auto [prev_l, prev_r, i] = queries[0];
    for (int i = prev_l; i <= prev_r; i++) {
        cnt[nums[i]]++;
        sum += 1LL * (cnt[nums[i]] * 2 - 1) * nums[i];
    }
    ans[i] = sum;
    for (int t = 1; t < T; t++) {
        auto [l, r, i] = queries[t];
        for (int i = prev_l; i < l; i++) {
            sum -= 1LL * (cnt[nums[i]] * 2 - 1) * nums[i];
            cnt[nums[i]]--;
        }
        for (int i = l; i < prev_l; i++) {
            cnt[nums[i]]++;
            sum += 1LL * (cnt[nums[i]] * 2 - 1) * nums[i];
        }
        for (int i = r + 1; i <= prev_r; i++) {
            sum -= 1LL * (cnt[nums[i]] * 2 - 1) * nums[i];
            cnt[nums[i]]--;
        }
        for (int i = prev_r + 1; i <= r; i++) {
            cnt[nums[i]]++;
            sum += 1LL * (cnt[nums[i]] * 2 - 1) * nums[i];
        }
        ans[i] = sum;
        prev_l = l;
        prev_r = r;
    }
    for (int i = 0; i < T; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
