#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> counts(8001);
    int sum = 0;
    int freq = 0;
    vector<int> freq_nums;
    int min_num = 4000;
    int max_num = -4000;
    for (int& num : nums) {
        cin >> num;
        sum += num;
        if (num < min_num) {
            min_num = num;
        }
        if (num > max_num) {
            max_num = num;
        }
        counts[num + 4000]++;
        if (counts[num + 4000] > freq) {
            freq_nums.clear();
            freq_nums.emplace_back(num);
            freq = counts[num + 4000];
        } else if (counts[num + 4000] == freq) {
            freq_nums.emplace_back(num);
        }
    }
    sort(nums.begin(), nums.end());
    cout << int(round(sum / double(N))) << "\n";
    cout << nums[N / 2] << "\n";
    if (freq_nums.size() > 1) {
        sort(freq_nums.begin(), freq_nums.end());
        cout << freq_nums[1] << "\n";
    } else {
        cout << freq_nums[0] << "\n";
    }
    cout << max_num - min_num << "\n";
    return 0;
}
