#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> X;
    int lo = 1;
    int hi = 4471;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int pre = mid * (mid + 1) / 2;
        if (pre >= X) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int idx = hi;
    int offset = X - idx * (idx + 1) / 2 - 1;
    if (idx % 2 == 0) {
        cout << idx + 1 - offset << "/" << 1 + offset << "\n";
    } else {
        cout << 1 + offset << "/" << idx + 1 - offset << "\n";
    }
    return 0;
}
