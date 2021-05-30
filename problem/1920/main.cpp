#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, M;
set<int> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int num;
    while (N-- > 0) {
        cin >> num;
        nums.insert(num);
    }
    cin >> M;
    while (M-- > 0) {
        cin >> num;
        if (nums.find(num) != nums.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
