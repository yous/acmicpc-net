#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N, M;
    cin >> N >> M;
    vector<short> nums(N);
    for (short& num : nums) {
        cin >> num;
    }
    short lo = 0;
    short hi = 9999;
    while (lo <= hi) {
        short mid = (lo + hi) / 2;
        int idx = 0;
        int cnt = 0;
        short cur_min = 10001;
        short cur_max = 0;
        while (idx < N) {
            cur_min = min(cur_min, nums[idx]);
            cur_max = max(cur_max, nums[idx]);
            if (cur_max - cur_min > mid) {
                cnt++;
                cur_min = cur_max = nums[idx];
            }
            idx++;
        }
        cnt++;
        if (cnt <= M) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
    return 0;
}
