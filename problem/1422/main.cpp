#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short K, N;
    cin >> K >> N;
    vector<string> nums(K);
    for (string& num : nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end(), [](const string& lhs, const string& rhs) {
        return lhs + rhs > rhs + lhs;
    });
    int max_idx = -1;
    int max_len = 0;
    for (int i = 0; i < K; i++) {
        int sz = nums[i].size();
        if (max_len < sz) {
            max_len = sz;
            max_idx = i;
        }
    }
    for (int i = 0; i < K; i++) {
        if (i == max_idx) {
            for (int j = 0; j < N - K; j++) {
                cout << nums[i];
            }
        }
        cout << nums[i];
    }
    cout << "\n";
    return 0;
}
