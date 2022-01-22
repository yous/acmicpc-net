#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> nums(1 << 25);
    int num;
    cin >> num;
    nums[num] = true;
    cout << num;
    while (cin >> num) {
        if (!nums[num]) {
            nums[num] = true;
            cout << " " << num;
        }
    }
    cout << "\n";
    return 0;
}
