#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> c;
        while (nums.size() >= 2) {
            auto ed = prev(nums.end());
            b = *ed;
            a = *prev(ed);
            if (a >= b && b <= c) {
                int cost = min(a, c);
                ans += cost;
                nums.pop_back();
            } else {
                break;
            }
        }
        if (nums.size() == 1) {
            b = nums[0];
            if (b <= c) {
                ans += c;
                nums.pop_back();
            }
        }
        nums.emplace_back(c);
    }
    if (nums.size() >= 2) {
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            ans += nums[i];
        }
    }
    cout << ans << "\n";
    return 0;
}
