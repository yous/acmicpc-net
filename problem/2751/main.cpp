#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
bool nums[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int num;
    while (N-- > 0) {
        cin >> num;
        nums[num + 1000000] = true;
    }
    for (int i = 0; i <= 2000000; i++) {
        if (nums[i]) {
            cout << i - 1000000 << "\n";
        }
    }
    return 0;
}
