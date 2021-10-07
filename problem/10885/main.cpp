#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = static_cast<int>(1e9) + 7;
int T, N;
vector<int> nums;

pair<int, int> solve(int lo, int hi, int neg_cnt) {
    if (lo > hi) {
        return {-2, 1};
    } else if (lo == hi) {
        return {nums[lo], 1};
    }
    if (neg_cnt % 2 == 0) {
        int res_cnt = 0;
        for (int i = lo; i <= hi; i++) {
            if (abs(nums[i]) == 2) {
                res_cnt++;
            }
        }
        return {2, res_cnt};
    } else if (neg_cnt == 1) {
        int before_cnt = 0;
        int after_cnt = 0;
        int idx = lo;
        while (nums[idx] > 0) {
            if (nums[idx] == 2) {
                before_cnt++;
            }
            idx++;
        }
        idx++;
        while (idx <= hi) {
            if (nums[idx] == 2) {
                after_cnt++;
            }
            idx++;
        }
        return {2, max(before_cnt, after_cnt)};
    } else {
        int before_cnt = 0;
        int after_cnt = 0;
        int first_idx = lo;
        while (true) {
            if (abs(nums[first_idx]) == 2) {
                before_cnt++;
            }
            if (nums[first_idx] < 0) {
                break;
            }
            first_idx++;
        }
        int last_idx = hi;
        while (true) {
            if (abs(nums[last_idx]) == 2) {
                after_cnt++;
            }
            if (nums[last_idx] < 0) {
                break;
            }
            last_idx--;
        }
        int in_cnt = 0;
        for (int i = first_idx + 1; i < last_idx; i++) {
            if (abs(nums[i]) == 2) {
                in_cnt++;
            }
        }
        return {2, max(before_cnt, after_cnt) + in_cnt};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> N;
        nums.resize(N);
        int neg_cnt = 0;
        int lo = 0;
        pair<int, int> ans = {-2, 1};
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            if (nums[i] == 0) {
                ans = max({ans, make_pair(0, 1), solve(lo, i - 1, neg_cnt)});
                neg_cnt = 0;
                lo = i + 1;
            } else if (nums[i] < 0) {
                neg_cnt++;
            }
        }
        ans = max(ans, solve(lo, N - 1, neg_cnt));
        switch (ans.first) {
            case -2:
            case -1:
            case 0:
            case 1:
                cout << (ans.first + MOD) % MOD << "\n";
                break;
            case 2:
                int res = 1;
                int mul = 2;
                int cnt = ans.second;
                while (cnt > 0) {
                    if (cnt % 2 == 1) {
                        res = 1LL * res * mul % MOD;
                        cnt--;
                    } else {
                        mul = 1LL * mul * mul % MOD;
                        cnt /= 2;
                    }
                }
                cout << res << "\n";
                break;
        }
    }
    return 0;
}
