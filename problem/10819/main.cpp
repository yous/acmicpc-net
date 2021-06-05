#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> nums;

int solve(int index, int sum, vector<int>& arr, vector<bool>& selected) {
    if (index == N) {
        return sum;
    }
    int _max = 0;
    for (int i = 0; i < N; i++) {
        if (!selected[i]) {
            int dist = 0;
            if (!arr.empty()) {
                dist = abs(nums[i] - arr.back());
            }
            selected[i] = true;
            arr.push_back(nums[i]);
            _max = max(_max, solve(index + 1, sum + dist, arr, selected));
            selected[i] = false;
            arr.pop_back();
        }
    }
    return _max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<int> arr{};
    vector<bool> selected(N, false);
    cout << solve(0, 0, arr, selected) << "\n";
    return 0;
}
