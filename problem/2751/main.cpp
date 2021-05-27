#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int nums[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int num;
    while (N-- > 0) {
        cin >> num;
        nums[num + 1000000]++;
    }
    for (int i = 0; i <= 2000000; i++) {
        int count = nums[i];
        for (int j = 0; j < count; j++) {
            cout << i - 1000000 << "\n";
        }
    }
    return 0;
}
