#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<bool> nums(1 << 25);
    bool first = true;
    int num;
    while (cin >> num) {
        if (!nums[num]) {
            nums[num] = true;
            if (first) {
                first = false;
                cout << num;
            } else {
                cout << " " << num;
            }
        }
    }
    cout << "\n";
    return 0;
}
