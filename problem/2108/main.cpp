#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> nums;
int counts[8001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int i;
    int sum = 0;
    int freq = 0;
    set<int> freq_nums;
    int min_num = 4000;
    int max_num = -4000;
    for (i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
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
            freq_nums.insert(num);
            freq = counts[num + 4000];
        } else if (counts[num + 4000] == freq) {
            freq_nums.insert(num);
        }
    }
    sort(nums.begin(), nums.end());
    cout << round(sum / static_cast<double>(N)) << "\n";
    cout << nums[N / 2] << "\n";
    if (freq_nums.size() > 1) {
        cout << *next(freq_nums.begin()) << "\n";
    } else {
        cout << *freq_nums.begin() << "\n";
    }
    cout << max_num - min_num << "\n";
    return 0;
}
