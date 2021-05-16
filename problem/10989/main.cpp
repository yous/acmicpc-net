#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int nums[10001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N-- > 0) {
        int num;
        cin >> num;
        nums[num] += 1;
    }
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < nums[i]; j++) {
            cout << i << "\n";
        }
    }
    return 0;
}
