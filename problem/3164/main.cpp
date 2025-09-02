#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    long long ans = 0;
    for (int y = Y1; y < Y2; y++) {
        if (y % 2 == 1) {
            if (X1 <= y) {
                ans += min(X2 - 1, y) - X1 + 1;
            }
        }
        if (X2 - 1 > y) {
            if ((X2 - 1) % 2 == 0) {
                ans += (X2 - 1 - max(y + 1, X1) + 1) / 2;
            } else {
                ans += (X2 - 1 - max(y + 1, X1) + 2) / 2;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
