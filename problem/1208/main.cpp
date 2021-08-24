#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> left_nums;
vector<int> right_nums;
vector<int> left_counts;
vector<int> right_counts;

int solve(vector<int>& nums, vector<int>& counts, int min_val, int max_val) {
    int sz = nums.size();
    int offset = min_val;
    min_val = 0;
    max_val = 0;
    for (int i = 0; i < sz; i++) {
        int num = nums[i];
        if (num >= 0) {
            for (int n = max_val - offset; n >= min_val - offset; n--) {
                counts[n + num] += counts[n];
            }
        } else {
            for (int n = min_val - offset; n <= max_val - offset; n++) {
                counts[n + num] += counts[n];
            }
        }
        counts[num - offset]++;
        if (num >= 0) {
            max_val += num;
        } else {
            min_val += num;
        }
    }
    if (S < min_val || S > max_val) {
        return 0;
    } else {
        return counts[S - offset];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    if (N == 1) {
        int num;
        cin >> num;
        if (num == S) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        return 0;
    }
    int left_min_val = 0;
    int left_max_val = 0;
    for (int i = 0; i < N / 2; i++) {
        int num;
        cin >> num;
        if (num >= 0) {
            left_max_val += num;
        } else {
            left_min_val += num;
        }
        left_nums.push_back(num);
    }
    int left_sz = left_max_val - left_min_val + 1;
    left_counts.resize(left_sz);
    int right_min_val = 0;
    int right_max_val = 0;
    for (int i = N / 2; i < N; i++) {
        int num;
        cin >> num;
        if (num >= 0) {
            right_max_val += num;
        } else {
            right_min_val += num;
        }
        right_nums.push_back(num);
    }
    int right_sz = right_max_val - right_min_val + 1;
    right_counts.resize(right_sz);
    long long ans = 0;
    ans += solve(left_nums, left_counts, left_min_val, left_max_val);
    ans += solve(right_nums, right_counts, right_min_val, right_max_val);
    int left_idx = 0;
    while (left_idx < left_sz && left_counts[left_idx] == 0) {
        left_idx++;
    }
    int right_idx = right_sz - 1;
    while (right_idx >= 0 && right_counts[right_idx] == 0) {
        right_idx--;
    }
    while (left_idx < left_sz && right_idx >= 0) {
        int sum = left_idx + left_min_val + right_idx + right_min_val;
        if (sum < S) {
            left_idx++;
            while (left_idx < left_sz && left_counts[left_idx] == 0) {
                left_idx++;
            }
        } else if (sum > S) {
            right_idx--;
            while (right_idx >= 0 && right_counts[right_idx] == 0) {
                right_idx--;
            }
        } else {
            ans += 1LL * left_counts[left_idx] * right_counts[right_idx];
            left_idx++;
            while (left_idx < left_sz && left_counts[left_idx] == 0) {
                left_idx++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
