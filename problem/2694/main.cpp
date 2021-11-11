#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, M;
vector<short> nums;

bool check(int lo, int sum) {
    if (lo >= M) {
        return true;
    }
    int cur_sum = 0;
    for (int i = lo; i < M; i++) {
        cur_sum += nums[i];
        if (cur_sum > sum) {
            return false;
        }
        if (cur_sum == sum) {
            return check(i + 1, sum);
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T-- > 0) {
        cin >> M;
        nums.resize(M);
        int max_num = 0;
        int total = 0;
        for (short& num : nums) {
            cin >> num;
            if (max_num < num) {
                max_num = num;
            }
            total += num;
        }
        int cur_sum = 0;
        for (int i = 0; i < M; i++) {
            cur_sum += nums[i];
            if (cur_sum >= max_num && total % cur_sum == 0 && check(i + 1, cur_sum)) {
                break;
            }
        }
        cout << cur_sum << "\n";
    }
    return 0;
}
