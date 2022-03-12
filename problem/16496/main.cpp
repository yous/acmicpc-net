#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short N;
    cin >> N;
    vector<string> nums(N);
    for (string& num : nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end(), [](const string& lhs, const string& rhs) {
        return lhs + rhs > rhs + lhs;
    });
    if (nums[0] == "0") {
        cout << "0\n";
    } else {
        for (int i = 0; i < N; i++) {
            cout << nums[i];
        }
        cout << "\n";
    }
    return 0;
}
