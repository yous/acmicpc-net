#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> nums;
vector<long long> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    int max_val = 0;
    int min_val = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num >= 0) {
            max_val += num;
        } else {
            min_val += num;
        }
        nums.push_back(num);
    }
    cnt.resize(max_val - min_val + 1);
    int offset = min_val;
    min_val = 0;
    max_val = 0;
    for (int i = 0; i < N; i++) {
        int num = nums[i];
        if (num >= 0) {
            for (int n = max_val - offset; n >= min_val - offset; n--) {
                cnt[n + num] += cnt[n];
            }
        } else {
            for (int n = min_val - offset; n <= max_val - offset; n++) {
                cnt[n + num] += cnt[n];
            }
        }
        cnt[num - offset]++;
        if (num >= 0) {
            max_val += num;
        } else {
            min_val += num;
        }
    }
    if (S < min_val || S > max_val) {
        cout << "0\n";
    } else {
        cout << cnt[S - offset] << "\n";
    }
    return 0;
}
