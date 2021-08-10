#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    int cur_sum = 0;
    int lo = 0;
    int hi = -1;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (hi == -1) {
            cur_sum += num;
            if (cur_sum >= S) {
                hi = i;
            }
        }
        nums.push_back(num);
    }
    if (hi == -1) {
        cout << "0\n";
    } else {
        int min_len = hi - lo + 1;
        while (hi < N) {
            cur_sum -= nums[lo];
            lo++;
            while (cur_sum < S && hi < N - 1) {
                hi++;
                cur_sum += nums[hi];
            }
            if (cur_sum < S) {
                break;
            } else {
                if (hi - lo + 1 < min_len) {
                    min_len = hi - lo + 1;
                }
            }
        }
        cout << min_len << "\n";
    }
    return 0;
}
