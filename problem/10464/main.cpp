#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solve(int n) {
    int ans = (n % 4 == 1 || n % 4 == 2) ? 1 : 0;
    int rem = n;
    for (int i = 30; i >= 1; i--) {
        if ((rem & (1 << i)) != 0) {
            rem -= 1 << i;
            int cnt = 1 + rem;
            if (cnt % 2 == 1) {
                ans |= (1 << i);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short T;
    cin >> T;
    while (T-- > 0) {
        int S, F;
        cin >> S >> F;
        cout << (solve(F) ^ solve(S - 1)) << "\n";
    }
    return 0;
}
