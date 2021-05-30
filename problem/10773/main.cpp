#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int K;
vector<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    int num;
    while (K-- > 0) {
        cin >> num;
        if (num == 0) {
            nums.pop_back();
        } else {
            nums.push_back(num);
        }
    }
    cout << accumulate(nums.begin(), nums.end(), 0) << "\n";
    return 0;
}
